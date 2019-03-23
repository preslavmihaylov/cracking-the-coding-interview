#include <bits/stdc++.h>
#include <sys/stat.h>
#include <pstructs/heap.h>

using namespace std;

// generate big file by running command:
// $ gpw 1000000 10 >> big-file.txt

class StringFSIndexTuple
{
public:
    string key;
    int fsIndex;
    
    StringFSIndexTuple() : StringFSIndexTuple("", 0) {}
    StringFSIndexTuple(string&& key, int fsIndex) : StringFSIndexTuple(key, fsIndex) {}
    StringFSIndexTuple(string& key, int fsIndex)
    {
        this->key = key;
        this->fsIndex = fsIndex;
    }

    bool operator<(const StringFSIndexTuple& other) const
    {
        return this->key < other.key;
    }

    bool operator>(const StringFSIndexTuple& other) const
    {
        return this->key > other.key;
    }

    bool operator==(const StringFSIndexTuple& other) const
    {
        return !(*this < other) && !(*this > other);
    }
};

void sortFile(string& filename, int maxLinesPerPiece);
void flushBufferToFile(vector<string>& buffer, string& filename);
void mergePieces(string& outputFilename, string& piecesDir, int piecesCnt);
void log(string msg)
{
    cout << msg << endl;
}

static const int MAX_LINES_PER_PIECE = 1000;

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    
    string filename = argv[1];
    sortFile(filename, MAX_LINES_PER_PIECE);
}

void sortFile(string& filename, int maxLinesPerPiece)
{
    string piecesDir = "./.pieces";
    int err = system(string("mkdir " + piecesDir).c_str());
    if (err != 0) exit(err);

    ifstream fs(filename);
    
    vector<string> currentBuffer;
    string line;
    int currentLine = 0;
    int currentPiece = 0;

    getline(fs, line);
    while (!fs.eof())
    {
        currentBuffer.push_back(line);
        currentLine++;

        if (currentLine>= maxLinesPerPiece)
        {
            std::sort(currentBuffer.begin(), currentBuffer.end());
            string pieceFilename = piecesDir + "/p" + std::to_string(currentPiece);
            flushBufferToFile(currentBuffer, pieceFilename);

            currentPiece++;
            currentLine %= maxLinesPerPiece;
            currentBuffer.clear();
        }

        getline(fs, line);
    }

    if (currentBuffer.size() > 0)
    {
        for (int i = 0; i < currentBuffer.size(); i++)
        {
            cout << "BUFF: " << currentBuffer[i] << endl;
        }

        std::sort(currentBuffer.begin(), currentBuffer.end());
        string pieceFilename = piecesDir + "/p" + std::to_string(currentPiece);
        flushBufferToFile(currentBuffer, pieceFilename);

        currentPiece++;
        currentLine %= maxLinesPerPiece;
        currentBuffer.clear();
    }

    string output = "output.txt";
    mergePieces(output, piecesDir, currentPiece);

    err = system(string("rm -r " + piecesDir).c_str());
    if (err != 0) exit(err);
}

void flushBufferToFile(vector<string>& buffer, string& filename)
{
    ofstream ofs(filename);
    for (int i = 0; i < buffer.size(); i++)
    {
        ofs << buffer[i] << endl;
    }
}

void mergePieces(string& outputFilename, string& piecesDir, int piecesCnt)
{
    vector<ifstream> piecesFS;
    for (int i = 0; i < piecesCnt; i++)
    {
        piecesFS.push_back(ifstream(piecesDir + "/p" + std::to_string(i)));
    }

    string line;
    ofstream outputFS(outputFilename);
    pstructs::min_heap<StringFSIndexTuple> orderedBuffer;

    for (int i = 0; i < piecesCnt; i++)
    {
        getline(piecesFS[i], line);
        if (!piecesFS[i].eof())
        {
            orderedBuffer.push(StringFSIndexTuple(line, i));
        }
    }

    while (orderedBuffer.getSize() > 0)
    {
        StringFSIndexTuple poppedTuple = orderedBuffer.pop();
        outputFS << poppedTuple.key << endl;

        ifstream& currentFS = piecesFS[poppedTuple.fsIndex];
        getline(currentFS, line);
        if (!currentFS.eof())
        {
            orderedBuffer.push(StringFSIndexTuple(line, poppedTuple.fsIndex));
        }
    }
}

