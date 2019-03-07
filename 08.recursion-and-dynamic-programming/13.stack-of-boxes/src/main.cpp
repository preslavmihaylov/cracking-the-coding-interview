#include <bits/stdc++.h>

using namespace std;

class Box
{
public:
    int width;
    int height;
    int depth;

    Box(int width, int height, int depth) : width(width), height(height), depth(depth) {}
};

int calculateHighestStack(const vector<shared_ptr<Box>>& boxes);
int calculateHighestStack(const vector<shared_ptr<Box>>& boxes, int startIndex, vector<int>& heights, 
                          int minWidth, int minHeight, int minDepth);

int main()
{
    int boxesCnt;
    cin >> boxesCnt;

    vector<shared_ptr<Box>> boxes;
    for (int i = 0; i < boxesCnt; i++)
    {
        int width, height, depth;
        cin >> width >> height >> depth;

        boxes.push_back(make_shared<Box>(width, height, depth));
    }

    int highestStack = calculateHighestStack(boxes);
    cout << highestStack << endl;
}

int calculateHighestStack(const vector<shared_ptr<Box>>& boxes)
{
    vector<shared_ptr<Box>> boxesCopy = boxes;
    std::sort(boxesCopy.begin(), boxesCopy.end(), 
        [](const shared_ptr<Box>& box1, const shared_ptr<Box>& box2) 
        { 
            return box1->height < box2->height;
        });

    vector<int> heights;
    for (int i = 0; i < boxes.size(); i++)
    {
        heights.push_back(-1);
    }

    return calculateHighestStack(boxesCopy, 0, heights, 0, 0, 0);
}

int calculateHighestStack(const vector<shared_ptr<Box>>& boxes, int startIndex, vector<int>& heights, 
                          int minWidth, int minHeight, int minDepth)
{
    int maxHeight = 0;
    for (int i = startIndex; i < boxes.size(); i++)
    {
        shared_ptr<Box> box = boxes[i];
        if (box->width >= minWidth && box->height >= minHeight && box->depth >= minDepth)
        {
            int currentHeight;
            if (heights[i] != -1)
            {
                currentHeight = heights[i];
            }
            else
            {
                currentHeight = box->height + calculateHighestStack(boxes, i + 1, heights, box->width + 1, 
                                                                    box->height + 1, box->depth + 1);
                heights[i] = currentHeight;
            }
            
            maxHeight = max(maxHeight, currentHeight);
        }
    }

    return maxHeight;
}

