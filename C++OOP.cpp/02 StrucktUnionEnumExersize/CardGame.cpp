#include <iostream>

using namespace std;

/*
    Да се напише програма, която реализира следната игра на карти.
    Единият от играчите показва на другия три карти, след което ги
    поставя пред себе си с лицето надолу и ги размества неколкократно.
    Вторият играч трябва да познае къде се намира определена карта.
*/

// константи, описващи четирите бои
const int CLUBS = 0;
const int DIAMONDS = 1;
const int HEARTS = 2;
const int SPADES = 3;

// константи, описващи силата
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

struct Card
{
    // силата на картата: от 2 до 10 + вале, дама, поп и асо
    int rank;
    // боята на картата
    int suit;
};

void showCard(const Card& card)
{
    cout << "Kарта е: ";

    // извеждаме силата на картата
    switch(card.rank)
    {
        case 2:
        case 3:
        case 4:
        case 9:
            cout << card.rank << "-ка "; break;

        case 5:
        case 6:
        case 7:
        case 8:
            cout << card.rank << "-ца "; break;

        case JACK:
            cout << "Вале "; break;

        case QUEEN:
            cout << "Дама "; break;

        case KING:
            cout << "Поп "; break;

        case ACE:
            cout << "Асо "; break;

        default:
            cout << "неизвестна ";
    }

    // извеждаме боята
    switch(card.suit)
    {
        case CLUBS:
            cout << "Пика\n"; break;

        case DIAMONDS:
            cout << "Каро\n"; break;

        case HEARTS:
            cout << "Купа\n"; break;

        case SPADES:
            cout << "Спатия\n"; break;

        default:
            cout << "неизвестна ";
    }
}

void playGame()
{
    // примерно иницализиране на 3 карти
    Card card1 = {2, CLUBS};
    showCard(card1);

    Card card2 = {QUEEN, HEARTS};
    showCard(card2);

    Card card3 = {8, SPADES};
    showCard(card3);

    // запомняне на картата, която търсим
    Card winnerCard = card2;

    // разместване на картите
    cout << "Разместване на карта 1 с карта 3";
    Card temp = card1;
    card1 = card3;
    card3 = temp;

    cout << "Разместване на карта 2 с карта 3";
    temp = card2;
    card2 = card3;
    card3 = temp;

    cout << "Разместване на карта 1 с карта 2";
    temp = card1;
    card1 = card2;
    card2 = temp;

    cout << "Коя е картата, която търсим?\n";
    showCard(winnerCard);

    cout << "Посочете на коя позиция е картата, която търсим?\n";

    int position;
    cin >> position;

    Card chosenCard;

    switch(position)
    {
        case 1: chosenCard = card1; break;
        case 2: chosenCard = card2; break;
        case 3: chosenCard = card3; break;

        default: cout << "Невалидна позиция";
    }

    cout << "Коя карта посочихте?\n";
    showCard(chosenCard);

    // сравняване с търсената карта
    // За съжаление все още не можем да използваме оператор ==
    if(chosenCard.rank == winnerCard.rank &&
       chosenCard.suit == winnerCard.suit)
       {
           cout << "БРАВО! ВИЕ ПЕЧЕЛИТЕ! \n";
       }
       else
       {
           cout << "СЪЖАЛЯВАМ! ВИЕ ГУБИТЕ! \n";
       }
}

int main()
{
    // Задача за дом: Игра на карти
    playGame();

    return 0;
}
