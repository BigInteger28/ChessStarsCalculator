#include <iostream>

using namespace std;

double newSystemCalc(double stijgingPerWin, double stijgingPerDraw, double dalingPerLose, double ratingPerWin, double ownRating, double sumRatingAllOpponents, double matches, double wins, double draws, double lost)
{
    double score = ((stijgingPerWin * wins) + (stijgingPerDraw * draws) - (dalingPerLose * lost)) / (stijgingPerWin / ratingPerWin);
    double ratingDifferenceOpponent = (sumRatingAllOpponents / matches) - ownRating;
    double ratingChangeFactor;

    if (ratingDifferenceOpponent >= 0) 
    {
        if (score >= 0)
        {
            ratingChangeFactor = (ratingDifferenceOpponent / 10) + 1;
            return ownRating + (ratingChangeFactor * score);
        }
        ratingChangeFactor = (ratingDifferenceOpponent / 10) + 1;
        return ownRating + (score / ratingChangeFactor);
    }
    if (score >= 0)
    {
        ratingChangeFactor = (-ratingDifferenceOpponent / 10) + 1;
        return ownRating + (score / ratingChangeFactor);
    }
    ratingChangeFactor = (-ratingDifferenceOpponent / 10) + 1;
    return ownRating + (ratingChangeFactor * score);
}

int main()
{
    while (1 != 2)
    {
        double stijgingPerWin = 3;
        double stijgingPerDraw = 1;
        double dalingPerLose = 3;
        double ratingPerWin = 1;

        double ownRating;        
        double sumRatingAllOpponents;        
        double matches;
        double wins;
        double draws;
        double lost;

        cout << "Your own rating: ";
        cin >> ownRating;        
        cout << "Total sum all ratings played against: ";
        cin >> sumRatingAllOpponents;        
        cout << "Matches played: ";
        cin >> matches;
        cout << "Total wins: ";
        cin >> wins;
        cout << "Total draws: ";
        cin >> draws;
        cout << "Total lost: ";
        cin >> lost;
        
        cout << "\nAverage opponents rating is " << sumRatingAllOpponents / matches;
        cout << "\nYour new rating is " << newSystemCalc(stijgingPerWin, stijgingPerDraw, dalingPerLose, ratingPerWin, ownRating, sumRatingAllOpponents, matches, wins, draws, lost);
        cout << "\n\n";
    }
}
