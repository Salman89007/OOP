#include <iostream>
#include <cstring>
using namespace std;

class Repository;
void objectCreated();
void objectDestroyed();
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
        objectCreated();
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
        objectCreated();
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
        objectCreated();
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
        objectDestroyed();
    }
};

bool compareBlobs(const Blob &a, const Blob &b)
{
    return strcmp(a.filename, b.filename) == 0 &&
           strcmp(a.contents, b.contents) == 0;
}

class Commit
{
    char *message;  // OWNS
    Blob *snapshot; // OWNS — array of Blob OBJECTS
    int fileCount = 0;
    const int commitID; // initialiser list only
    Commit *parent;     // OBSERVES — do not delete

public:
    Commit() : commitID(0)
    {
        parent = nullptr;
        message = nullptr;
        snapshot = nullptr;
        objectCreated();
    }
    Commit(const int commitID, const char *message) : commitID(commitID) // this will run in the beginning
    {
        int len = strlen(message);
        this->message = new char[len + 1];
        strcpy(this->message, message);
        snapshot = nullptr;
        parent = nullptr;
        fileCount = 0;
        objectCreated();
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
        objectCreated();
    }
    int getFileCount() const
    {
        return fileCount;
    }
    const Blob &getBlob(int i) const { return snapshot[i]; }
    int getID() const { return commitID; }
    const char *getMessage() const { return message; }
    int getTotalBytes() const
    {
        int total = 0;
        for (int i = 0; i < fileCount; i++)
            total += snapshot[i].getByteCount();
        return total;
    }
    const Blob *findBlob(const char *name) const
    {
        for (int i = 0; i < fileCount; i++)
        {
            if (strcmp(snapshot[i].getFilename(), name) == 0)
                return &snapshot[i];
        }
        return nullptr;
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
    bool replaceBlob(const char *name, const char *text)
    {
        for (int i = 0; i < fileCount; i++)
        {
            if (strcmp(snapshot[i].getFilename(), name) == 0)
            {
                snapshot[i].setContent(text);
                return true;
            }
        }
        return false;
    }
    void clearBlobs()
    {
        delete[] snapshot;
        snapshot = nullptr;
        fileCount = 0;
    }
    void setMessage(const char *m)
    {
        delete[] message;
        message = new char[strlen(m) + 1];
        strcpy(message, m);
    }
    void show() const
    {
        for (int i = 0; i < fileCount; i++)
        {
            cout << snapshot[i].getFilename() << " | " << snapshot[i].getContent() << endl;
        }
    }
    void copyBlobsFrom(const Commit &other)
    {
        for (int i = 0; i < other.fileCount; i++)
            addBlob(other.snapshot[i].getFilename(), other.snapshot[i].getContent());
    }
    void setParent(Commit *p) { parent = p; }
    ~Commit()
    {
        delete[] message;
        delete[] snapshot;
        objectDestroyed();
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
        objectCreated();
    };
    Branch(const int branchID, const char *name) : branchID(branchID)
    {
        int len = strlen(name);
        branchName = new char[len + 1];
        strcpy(branchName, name);
        history = nullptr;
        commitCount = 0;
        historyCapacity = 0;
        objectCreated();
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
        objectCreated();
    }
    int getCommitCount() const { return commitCount; }
    const Commit *getCommit(int i) const { return history[i]; }

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
        if (commitCount > 0)
            history[commitCount]->setParent(history[commitCount - 1]);
        commitCount++;
    }
    Commit *getLatest() const { return history[commitCount - 1]; }
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
    const char *getName() const { return branchName; }
    ~Branch()
    {
        for (int i = 0; i < commitCount; i++)
        {
            delete history[i];
        }
        delete[] history;
        delete[] branchName;
        objectDestroyed();
    }
};

class Repository
{
    Branch **branches;
    int branchCount, branchCapacity;
    Branch *head;   // observes, never delete
    Commit working; // tracked files live here
    static int objectsAlive;
    static int commitsEverMade;
    static int nextCommitID;
    void growBranches()
    {
        int newCap;
        if (branchCapacity == 0)
            newCap = 2;
        else
            newCap = branchCapacity * 2;
        Branch **bigger = new Branch *[newCap];
        for (int i = 0; i < branchCount; i++)
            bigger[i] = branches[i]; // addresses only
        delete[] branches;           // frees the slots, NOT the Commits
        branches = bigger;
        branchCapacity = newCap;
    }
    // true if a commit with this ID is also inside any branch other than index self
    bool sharedWithOther(int id, int self) const
    {
        for (int b = 0; b < branchCount; b++)
        {
            if (b == self)
                continue;
            for (int c = 0; c < branches[b]->getCommitCount(); c++)
            {
                if (branches[b]->getCommit(c)->getID() == id)
                    return true;
            }
        }
        return false;
    }
    // true if a commit with this ID is inside a branch with a lower index than self
    bool inLowerBranch(int id, int self) const
    {
        for (int b = 0; b < self; b++)
        {
            for (int c = 0; c < branches[b]->getCommitCount(); c++)
            {
                if (branches[b]->getCommit(c)->getID() == id)
                    return true;
            }
        }
        return false;
    }

public:
    Repository() : working(0, "working")
    {
        branches = nullptr;
        branchCount = 0;
        branchCapacity = 0;
        head = nullptr;
        objectCreated();
    }

    Repository(const Repository &sourceRef) : working(sourceRef.working)
    {
        branchCount = sourceRef.branchCount;
        branchCapacity = sourceRef.branchCapacity;

        if (branchCapacity == 0)
            branches = nullptr;
        else
            branches = new Branch *[branchCapacity];

        head = nullptr;
        for (int i = 0; i < branchCount; i++)
        {
            branches[i] = new Branch(*sourceRef.branches[i]);
            if (sourceRef.branches[i] == sourceRef.head)
                head = branches[i]; // observer points into the NEW array
        }
        objectCreated();
    }

    const Branch *getHead() const { return head; }

    void init()
    {
        if (head != nullptr)
        {
            cout << "Already initialised." << endl;
            return;
        }
        if (branchCount == branchCapacity)
        {
            growBranches();
        }
        branches[branchCount] = new Branch(0, "main");
        head = branches[branchCount];
        nextCommitID = 1;
        branchCount++;
        Commit c0(0, "initial commit");
        head->addCommit(c0);
        commitsEverMade++;
        cout << "Repository initialised. Branch 'main' created." << endl;
    }

    Repository &add(const char *name, const char *text)
    {
        if (!working.replaceBlob(name, text))
            working.addBlob(name, text);
        cout << "tracking " << name << " (" << strlen(text) << " bytes)" << endl;
        return *this;
    }

    Repository &commit(const char *msg)
    {
        if (head == nullptr)
        {
            cout << "Run init first." << endl;
            return *this;
        }
        Commit c(nextCommitID++, msg);
        c.copyBlobsFrom(working);
        head->addCommit(c);
        commitsEverMade++;
        cout << "[" << head->getName() << " #" << c.getID() << "] "
             << c.getMessage() << "  " << c.getFileCount() << " files, "
             << c.getTotalBytes() << " bytes" << endl;
        return *this;
    }

    void branch(const char *name)
    {
        if (head == nullptr)
        {
            cout << "Run init first." << endl;
            return;
        }
        if (branchCount == branchCapacity)
        {
            growBranches();
        }
        Branch *fresh = new Branch(*head);
        fresh->rename(name);
        branches[branchCount++] = fresh;
        cout << "Branch '" << name << "' copied from '" << head->getName() << "' ("
             << head->getCommitCount() - 1 << " commit, "
             << head->getLatest()->getFileCount() << " blobs)" << endl;
    }
    void diff(const char *nameA, const char *nameB) const
    {
        const Branch *a = nullptr;
        const Branch *b = nullptr;
        for (int i = 0; i < branchCount; i++)
        {
            if (strcmp(branches[i]->getName(), nameA) == 0)
                a = branches[i];
            if (strcmp(branches[i]->getName(), nameB) == 0)
                b = branches[i];
        }
        if (a == nullptr || b == nullptr)
        {
            cout << "No such branch." << endl;
            return;
        }
        const Commit *ca = a->getLatest();
        const Commit *cb = b->getLatest();
        for (int i = 0; i < ca->getFileCount(); i++)
        {
            cout << ca->getBlob(i).getFilename();
            const Blob *other = cb->findBlob(ca->getBlob(i).getFilename());
            if (other == nullptr)
                cout << " only in " << nameA << endl;
            else if (compareBlobs(ca->getBlob(i), *other))
                cout << " identical" << endl;
            else
                cout << " MODIFIED" << endl;
        }
        for (int i = 0; i < cb->getFileCount(); i++)
        {
            if (ca->findBlob(cb->getBlob(i).getFilename()) == nullptr)
                cout << cb->getBlob(i).getFilename() << " only in " << nameB << endl;
        }
    }

    Repository &checkout(const char *name)
    {
        for (int i = 0; i < branchCount; i++)
        {
            if (strcmp(branches[i]->getName(), name) == 0)
            {
                head = branches[i];
                working.clearBlobs();
                working.copyBlobsFrom(*head->getLatest()); // tracked files follow the branch
                cout << "Now on branch '" << name << "'." << endl;
                return *this;
            }
        }
        cout << "No such branch." << endl;
        return *this;
    }

    void show() const
    {
        if (head == nullptr)
        {
            cout << "Run init first." << endl;
            return;
        }
        head->getLatest()->show();
    }

    void log() const
    {
        if (head == nullptr)
        {
            cout << "Run init first." << endl;
            return;
        }
        bool printed = false;
        // commits that live on only one branch, newest branch first
        for (int b = branchCount - 1; b >= 0; b--)
        {
            int indent = branchCount - 1 - b;
            int last = branches[b]->getCommitCount() - 1;
            bool first = true;
            for (int c = last; c >= 0; c--)
            {
                const Commit *cm = branches[b]->getCommit(c);
                if (sharedWithOther(cm->getID(), b))
                    continue;
                if (first && printed)
                {
                    for (int k = 0; k < indent - 1; k++)
                        cout << "| ";
                    cout << "|" << endl;
                }
                first = false;
                for (int k = 0; k < indent; k++)
                    cout << "| ";
                cout << "* #" << cm->getID() << " " << cm->getMessage()
                     << "   (" << branches[b]->getName() << ")";
                if (branches[b] == head && c == last)
                    cout << " <- HEAD";
                cout << endl;
                printed = true;
            }
        }
        if (printed)
            cout << "|/" << endl;
        // shared commits, printed once
        for (int b = 0; b < branchCount; b++)
        {
            for (int c = branches[b]->getCommitCount() - 1; c >= 0; c--)
            {
                const Commit *cm = branches[b]->getCommit(c);
                if (!sharedWithOther(cm->getID(), b) || inLowerBranch(cm->getID(), b))
                    continue;
                cout << "* #" << cm->getID() << " " << cm->getMessage();
                if (branches[b] == head && c == branches[b]->getCommitCount() - 1)
                    cout << " <- HEAD";
                cout << endl;
            }
        }
    }

    void stats() const
    {
        cout << "objects alive " << objectsAlive << " | commits ever " << commitsEverMade << endl;
    }
    static void objectCreated() { objectsAlive++; }
    static void objectDestroyed() { objectsAlive--; }
    static int getObjectsAlive() { return objectsAlive; }
    static int getCommitsEverMade() { return commitsEverMade; }

    ~Repository()
    {
        for (int i = 0; i < branchCount; i++)
            delete branches[i];
        delete[] branches;
        objectDestroyed();
    }
};

int Repository::objectsAlive = 0;
int Repository::commitsEverMade = 0;
int Repository::nextCommitID = 0;

void objectCreated() { Repository::objectCreated(); }
void objectDestroyed() { Repository::objectDestroyed(); }

void display(const Repository &r) // const Repository& — every getter used is const
{
    if (r.getHead() == nullptr)
    {
        cout << "Run init first." << endl;
        return;
    }
    const Commit &c = *r.getHead()->getLatest(); // a real const Commit
    c.show();
}

int main()
{
    cout << "objects alive " << Repository::getObjectsAlive() << endl;
    {
        Repository repo;
        char line[256];
        char cmd[256];
        while (true)
        {
            cout << "> ";
            if (!cin.getline(line, 256))
                break;
            int i = 0;
            while (line[i] != ' ' && line[i] != '\0')
            {
                cmd[i] = line[i];
                i++;
            }
            cmd[i] = '\0';

            if (strcmp(cmd, "exit") == 0)
                break;
            if (strcmp(cmd, "init") == 0)
                repo.init();
            if (strcmp(cmd, "show") == 0)
                display(repo);
            if (strcmp(cmd, "log") == 0)
                repo.log();
            if (strcmp(cmd, "cascade") == 0)
                repo.checkout("main").add("a.txt", "x").commit("msg");
            if (strcmp(cmd, "add") == 0)
            {
                char filename[256];
                char text[256];

                i++;
                int f = 0;
                while (line[i] != ' ' && line[i] != '\0')
                {
                    filename[f] = line[i];
                    f++;
                    i++;
                }
                filename[f] = '\0';

                i++;
                i++;
                int t = 0;
                while (line[i] != '"' && line[i] != '\0')
                {
                    text[t] = line[i];
                    t++;
                    i++;
                }
                text[t] = '\0';

                repo.add(filename, text);
            }
            if (strcmp(cmd, "commit") == 0)
            {
                char message[256];

                i++;
                i++;
                int m = 0;
                while (line[i] != '"' && line[i] != '\0')
                {
                    message[m] = line[i];
                    m++;
                    i++;
                }
                message[m] = '\0';

                repo.commit(message);
            }
            if (strcmp(cmd, "branch") == 0)
            {
                char name[256];

                i++;
                int n = 0;
                while (line[i] != ' ' && line[i] != '\0')
                {
                    name[n] = line[i];
                    n++;
                    i++;
                }
                name[n] = '\0';

                repo.branch(name);
            }
            if (strcmp(cmd, "checkout") == 0)
            {
                char name[256];

                i++;
                int n = 0;
                while (line[i] != ' ' && line[i] != '\0')
                {
                    name[n] = line[i];
                    n++;
                    i++;
                }
                name[n] = '\0';

                repo.checkout(name);
            }
            if (strcmp(cmd, "diff") == 0)
            {
                char nameA[256];
                char nameB[256];

                i++;
                int n = 0;
                while (line[i] != ' ' && line[i] != '\0')
                {
                    nameA[n] = line[i];
                    n++;
                    i++;
                }
                nameA[n] = '\0';

                i++;
                n = 0;
                while (line[i] != ' ' && line[i] != '\0')
                {
                    nameB[n] = line[i];
                    n++;
                    i++;
                }
                nameB[n] = '\0';

                repo.diff(nameA, nameB);
            }
            if (strcmp(cmd, "stats") == 0)
                repo.stats();
        }
    }

    cout << "destroying repository..." << endl;
    cout << "objects alive " << Repository::getObjectsAlive();
    if (Repository::getObjectsAlive() == 0)
        cout << " | no leaks";
    cout << endl;
    return 0;
}