#include <iostream>
#include <cstring>
using namespace std;

class Repository
{
    Branch **branches; // OWNS — array of Branch pointers
    int branchCount, branchCapacity;
    Branch *head;            // OBSERVES — do not delete
    static int objectsAlive; // ++ in every ctor, -- in every dtor
    static int commitsEverMade;
    static int nextCommitID;
    public:
    Repository(){

    }
};

class Branch
{
    char *branchName; // OWNS — new char[ ]
    Commit **history; // OWNS — array of Commit pointers
    int commitCount, historyCapacity;
    const int branchID;
    public:
    Branch(const int branchID) : branchID(branchID){

    }
};
class Commit
{
    char *message;  // OWNS
    Blob *snapshot; // OWNS — array of Blob OBJECTS
    int fileCount;
    const int commitID; // initialiser list only
    Commit *parent;
    public:
    Commit(const int commitID) : commitID(commitID){

    }
};
class Blob
{
    char *filename; // OWNS
    char *contents; // OWNS
    int byteCount;

public:
    Blob(){}
    Blob(const char *filename, const char *contents)//for B
    {
        int len1 = strlen(filename);
        this->filename = new char[len1 + 1];
        strcpy(this->filename, filename);

        int len2 = strlen(contents);
        byteCount = len2;
        this->contents = new char[len2 + 1];
        strcpy(this->contents, contents);
    }

    Blob(const Blob &sourceRef)//for second , in parameters we have B
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
int main()
{

    Blob B("notes 1", "bruce wayne");
    Blob second = B;
    second.setContent("clark kent");//second already contains bruce wayne 
    cout << "Content : " << B.getContent() << endl;
    cout << "Content : " << second.getContent() << endl;
    cout << "BYTE count : " << B.getByteCount() << endl;

    return 0;
}