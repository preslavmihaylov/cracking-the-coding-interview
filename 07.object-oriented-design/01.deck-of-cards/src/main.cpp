#include <bits/stdc++.h>

using namespace std;

enum CardColor 
{
    SPADES, DIAMONDS, HEARTS, CLUBS, COUNT
};

class Card
{
public:
    Card(int faceValue, CardColor color) : faceValue(faceValue), color(color) {}
    
    int getValue() { return faceValue; }
    CardColor getColor() { return color; }

protected:
    int faceValue;
    CardColor color;
};

typedef vector<shared_ptr<Card>> Hand;

class Deck
{
public:
    
    Deck(vector<shared_ptr<Card>>& initCards)
    {
        if (initCards.size() == 0)
        {
            init();
        }
        else
        {
            init(initCards);
        }
    }
    
    Deck(vector<shared_ptr<Card>>&& initCards) : Deck(initCards) {}
    Deck() : Deck(vector<shared_ptr<Card>>()) {}
    
    void init(vector<shared_ptr<Card>>& initCards)
    {
        cards = initCards;
    }

    void init()
    {
        for (int color = 0; color < CardColor::COUNT; color++)
        {
            for (int faceValue = 1; faceValue <= 13; faceValue++)
            {
                cards.push_back(make_shared<Card>(faceValue, (CardColor)color));
            }
        }
    }

    void shuffle()
    {
        // TODO: Shuffle deck
    }

    shared_ptr<Hand> dealHand(uint32_t handSize)
    {
        if (cards.size() < handSize) return nullptr;
        
        auto&& lowerBound = cards.begin() + cards.size() - handSize;
        auto&& upperBound = cards.begin() + cards.size();
        
        shared_ptr<Hand> hand = make_shared<Hand>(lowerBound, upperBound);
        cards.erase(lowerBound, upperBound);

        return hand;
    }

    shared_ptr<Card> dealCard()
    {
        if (cards.size() == 0) return nullptr;
        
        shared_ptr<Card> card = cards[cards.size() - 1];
        cards.erase(cards.begin() + cards.size() - 1);

        return card;
    }

private:
    vector<shared_ptr<Card>> cards;
};

class BlackJackService
{
public:
    // normally, I would use dependency injection, but it's out of scope for this task
    BlackJackService(vector<shared_ptr<Card>>& initCards) : deck(initCards) {}
    BlackJackService(vector<shared_ptr<Card>>&& initCards) : BlackJackService(initCards) {}
    BlackJackService() : deck() {}

    void shuffle()
    {
        deck.shuffle();
    }

    shared_ptr<Hand> dealHand(uint32_t handSize)
    {
        return deck.dealHand(handSize);
    }

    shared_ptr<Hand> dealHand()
    {
        return deck.dealHand(DEFAULT_HAND_SIZE);
    }

    shared_ptr<Card> dealCard()
    {
        return deck.dealCard();
    }

    static uint32_t calculateScore(shared_ptr<Hand> hand)
    {
        shared_ptr<vector<uint32_t>> scores = BlackJackService::possibleScores(hand);
        
        uint32_t maxUnder = 0;
        uint32_t minOver = UINT_MAX;
        for (uint32_t score : *scores)
        {
            if (score > 21 && score < minOver)
            {
                minOver = score;
            }
            else if (score <= 21 && score > maxUnder)
            {
                maxUnder = score;
            }
        }

        return maxUnder != 0 ? maxUnder : minOver;
    }

private:
    static const int DEFAULT_HAND_SIZE = 2;
    Deck deck;

    static shared_ptr<vector<uint32_t>> possibleScores(shared_ptr<Hand> hand)
    {
        shared_ptr<vector<uint32_t>> result = make_shared<vector<uint32_t>>();
        result->push_back(0);

        BlackJackService::possibleScores(hand, 0, *result, 0);

        return result;
    }

    static void possibleScores(shared_ptr<Hand> hand, uint32_t handIndex, 
                               vector<uint32_t>& scores, uint32_t scoreIndex)
    {
        if (handIndex == hand->size()) return;

        shared_ptr<Card> currentCard = hand->at(handIndex);
        if (currentCard->getValue() == 1)
        {
            scores.push_back(0);
            scores[scores.size() - 1] = scores[scoreIndex] + 11;
            possibleScores(hand, handIndex + 1, scores, scores.size() - 1);
        }
        
        if (currentCard->getValue() > 10)
        {
            scores[scoreIndex] += 10;
        }
        else
        {
            scores[scoreIndex] += currentCard->getValue();
        }

        possibleScores(hand, handIndex + 1, scores, scoreIndex);
    }
};

int main()
{
    vector<shared_ptr<Card>> startingCards;
    string line;
    getline(cin, line);

    istringstream iss(line);
    while (!iss.eof())
    {
        uint32_t face;
        iss >> face;
        
        // Color doesn't matter in this game, so I put it always spades by default
        startingCards.push_back(make_shared<Card>(face, CardColor::SPADES));
    }
    
    BlackJackService service(startingCards);
    
    shared_ptr<Hand> hand;

    string cmd = "";
    while (cmd != "exit")
    {
        cin >> cmd;
        if (cmd == "hand")
        {
            hand = service.dealHand();
        }
        else if (cmd == "card")
        {
            hand->push_back(service.dealCard());
        }
        else if (cmd == "score")
        {
            uint32_t score = service.calculateScore(hand);
            cout << score << endl;
        }
    }

    return 0;
}

