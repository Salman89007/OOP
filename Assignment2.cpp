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
};
class Branch
{
    char *branchName; // OWNS — new char[ ]
    Commit **history; // OWNS — array of Commit pointers
    int commitCount, historyCapacity;
    const int branchID;
};
class Commit
{
    char *message;  // OWNS
    Blob *snapshot; // OWNS — array of Blob OBJECTS
    int fileCount;
    const int commitID; // initialiser list only
    Commit *parent;

public:
    Commit(const char *M, const Blob* S, int FileCount)
    {
        message = new char[strlen(M) + 1];
        strcpy(message, M);

        snapshot = new Blob[FileCount];
        fileCount = FileCount;
        parent = nullptr;
    }
};

class Blob
{
private:
    char *filename;
    char *contents;
    int byteCount;

public:
    Blob()
    {
    }
    Blob(const char *Filename, const char *Content)
    {
        filename = new char[strlen(Filename) + 1];
        strcpy(filename, Filename);

        contents = new char[strlen(Content) + 1];
        strcpy(contents, Content);
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
}
int main()
{

    return 0;
}