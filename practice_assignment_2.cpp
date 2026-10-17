#include <iostream>
#include <cstring>
using namespace std;

class Blob
{
    char *filename; // OWNS
    char *contents; // OWNS
    int byteCount;

public:
    Blob()
    {
        filename = nullptr;
        contents = nullptr;
        byteCount = 0;
    }
    Blob(const char *filename, const char *contents) // for B
    {
        int len1 = strlen(filename);
        this->filename = new char[len1 + 1];
        strcpy(this->filename, filename);

        int len2 = strlen(contents);
        byteCount = len2;
        this->contents = new char[len2 + 1];
        strcpy(this->contents, contents);
    }

    Blob(const Blob &sourceRef) // for second , in parameters we have B
    {
        int len1 = strlen(sourceRef.filename);
        filename = new char[len1 + 1];
        strcpy(filename, sourceRef.filename);

        int len = strlen(sourceRef.contents);
        contents = new char[len + 1];
        strcpy(contents, sourceRef.contents);
        byteCount = sourceRef.byteCount;
    }
    void setContent(const char *content)
    {
        delete[] contents;
        int len = strlen(content);
        contents = new char[len + 1];
        strcpy(contents, content);
        byteCount = len;
    }
    const int getByteCount() const
    {
        return byteCount;
    }
    const char *getContent() const
    {
        return contents;
    }
    const char *getFilename() const { return filename; }
    void assignFrom(const Blob &other)
    {
        delete[] filename;
        delete[] contents;

        int len1 = strlen(other.filename);
        filename = new char[len1 + 1];
        strcpy(filename, other.filename);

        int len2 = strlen(other.contents);
        contents = new char[len2 + 1];
        strcpy(contents, other.contents);

        byteCount = other.byteCount;
    }
    friend bool compareBlobs(const Blob &, const Blob &);
    ~Blob()
    {
        delete[] filename;
        delete[] contents;
    }
};

bool compareBlobs(const Blob &, const Blob &)
{
    return true;
}

class Commit
{
    char *message;  // OWNS
    Blob *snapshot; // OWNS — array of Blob OBJECTS
    int fileCount = 0;
    const int commitID; // initialiser list only
    Commit *parent;

public:
    Commit() : commitID(0)
    {
        parent = nullptr;
        message = nullptr;
        snapshot = nullptr;
    }
    Commit(const int commitID, const char *message) : commitID(commitID) // this will run in the beginning
    {
        int len = strlen(message);
        this->message = new char[len + 1];
        strcpy(this->message, message);
        snapshot = nullptr;
        parent = nullptr;
        fileCount = 0;
    }
    Commit(const Commit &sourceRef) : commitID(sourceRef.commitID)
    {
        int len = strlen(sourceRef.message);
        this->message = new char[len + 1];
        strcpy(this->message, sourceRef.message);
        fileCount = sourceRef.fileCount;
        snapshot = new Blob[fileCount];
        for (int i = 0; i < fileCount; i++)
            snapshot[i].assignFrom(sourceRef.snapshot[i]);
        parent = sourceRef.parent;
    }
    int getFileCount() const
    {
        return fileCount;
    }
    void addBlob(const char *name, const char *text)
    {
        Blob *bigger = new Blob[fileCount + 1];
        for (int i = 0; i < fileCount; i++)
        {
            bigger[i].assignFrom(snapshot[i]);
        }
        Blob temp(name, text);
        bigger[fileCount].assignFrom(temp);
        delete[] snapshot;
        snapshot = bigger;
        fileCount++;
    }
    void show() const
    {
        for (int i = 0; i < fileCount; i++)
        {
            cout << snapshot[i].getFilename() << endl;
            cout << snapshot[i].getContent() << endl;
        }
    }
    void setParent(Commit *p) { parent = p; }
    ~Commit()
    {
        delete[] message;
        delete[] snapshot;
    }
};

class Branch
{
    char *branchName; // OWNS — new char[ ]
    Commit **history; // OWNS — array of Commit pointers
    int commitCount, historyCapacity;
    const int branchID;
    void growHistory()
    {
        int newCap;
        if (historyCapacity == 0)
            newCap = 2;
        else
            newCap = historyCapacity * 2;
        Commit **bigger = new Commit *[newCap];
        for (int i = 0; i < commitCount; i++)
            bigger[i] = history[i]; // addresses only
        delete[] history;           // frees the slots, NOT the Commits
        history = bigger;
        historyCapacity = newCap;
    }

public:
    Branch() : branchID(0)
    {
        branchName = nullptr;
        history = nullptr;
        commitCount = 0;
        historyCapacity = 0;
    };
    Branch(const int branchID, const char *name) : branchID(branchID)
    {
        int len = strlen(name);
        branchName = new char[len + 1];
        strcpy(branchName, name);
        history = nullptr;
        commitCount = 0;
        historyCapacity = 0;
    }
    Branch(const Branch &sourceRef) : branchID(sourceRef.branchID)
    {
        int len = strlen(sourceRef.branchName);
        branchName = new char[len + 1];
        strcpy(branchName, sourceRef.branchName);

        commitCount = sourceRef.commitCount;
        historyCapacity = sourceRef.historyCapacity;

        if (historyCapacity == 0)
            history = nullptr;
        else
            history = new Commit *[historyCapacity];

        for (int i = 0; i < commitCount; i++)
        {
            history[i] = new Commit(*sourceRef.history[i]);
            if (i > 0)
                history[i]->setParent(history[i - 1]); // point inside the NEW branch
        }
    }

    void rename(const char *newName)
    {
        delete[] branchName;
        int len = strlen(newName);
        branchName = new char[len + 1];
        strcpy(branchName, newName);
    }

    void addCommit(const Commit &c)
    {
        if (commitCount == historyCapacity)
            growHistory();
        history[commitCount] = new Commit(c); // copy constructor does the deep copy
        commitCount++;
    }
    void show() const
    {
        cout << "Branch " << branchName << ":" << endl;
        for (int i = 0; i < commitCount; i++)
            history[i]->show();
    }

    void addBlobToLast(const char *name, const char *text)
    {
        history[commitCount - 1]->addBlob(name, text);
    }
    ~Branch()
    {
        for (int i = 0; i < commitCount; i++)
        {
            delete history[i];
        }
        delete[] history;
        delete[] branchName;
    }
};

class Repository
{
    Branch **branches; // OWNS — array of Branch pointers
    int branchCount, branchCapacity;
    Branch *head;            // OBSERVES — do not delete
    static int objectsAlive; // ++ in every ctor, -- in every dtor
    static int commitsEverMade;
    static int nextCommitID;

public:
    Repository()
    {
    }
};

int main()
{
    Commit c1(1, "first draft");
    c1.addBlob("notes.txt", "chapter one");

    Branch a(0, "main");
    a.addCommit(c1);

    Branch b(a);
    b.rename("experiment");
    b.addBlobToLast("extra.txt", "hello");

    a.show();   // notes.txt only
    b.show();   // notes.txt and extra.txt
    return 0;
}