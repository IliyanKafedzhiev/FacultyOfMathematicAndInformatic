#include <iostream>

using namespace std;

/*
    �� �� ������ ��������, ����� ��������� �������� ���� �� �����.
    ������� �� �������� ������� �� ������ ��� �����, ���� ����� ��
    ������� ���� ���� �� � ������ ������ � �� ��������� �������������.
    ������� ����� ������ �� ������ ���� �� ������ ���������� �����.
*/

// ���������, �������� �������� ���
const int CLUBS = 0;
const int DIAMONDS = 1;
const int HEARTS = 2;
const int SPADES = 3;

// ���������, �������� ������
const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

struct Card
{
    // ������ �� �������: �� 2 �� 10 + ����, ����, ��� � ���
    int rank;
    // ����� �� �������
    int suit;
};

void showCard(const Card& card)
{
    cout << "K���� �: ";

    // ��������� ������ �� �������
    switch(card.rank)
    {
        case 2:
        case 3:
        case 4:
        case 9:
            cout << card.rank << "-�� "; break;

        case 5:
        case 6:
        case 7:
        case 8:
            cout << card.rank << "-�� "; break;

        case JACK:
            cout << "���� "; break;

        case QUEEN:
            cout << "���� "; break;

        case KING:
            cout << "��� "; break;

        case ACE:
            cout << "��� "; break;

        default:
            cout << "���������� ";
    }

    // ��������� �����
    switch(card.suit)
    {
        case CLUBS:
            cout << "����\n"; break;

        case DIAMONDS:
            cout << "����\n"; break;

        case HEARTS:
            cout << "����\n"; break;

        case SPADES:
            cout << "������\n"; break;

        default:
            cout << "���������� ";
    }
}

void playGame()
{
    // �������� ������������� �� 3 �����
    Card card1 = {2, CLUBS};
    showCard(card1);

    Card card2 = {QUEEN, HEARTS};
    showCard(card2);

    Card card3 = {8, SPADES};
    showCard(card3);

    // ��������� �� �������, ����� ������
    Card winnerCard = card2;

    // ����������� �� �������
    cout << "����������� �� ����� 1 � ����� 3";
    Card temp = card1;
    card1 = card3;
    card3 = temp;

    cout << "����������� �� ����� 2 � ����� 3";
    temp = card2;
    card2 = card3;
    card3 = temp;

    cout << "����������� �� ����� 1 � ����� 2";
    temp = card1;
    card1 = card2;
    card2 = temp;

    cout << "��� � �������, ����� ������?\n";
    showCard(winnerCard);

    cout << "�������� �� ��� ������� � �������, ����� ������?\n";

    int position;
    cin >> position;

    Card chosenCard;

    switch(position)
    {
        case 1: chosenCard = card1; break;
        case 2: chosenCard = card2; break;
        case 3: chosenCard = card3; break;

        default: cout << "��������� �������";
    }

    cout << "��� ����� ���������?\n";
    showCard(chosenCard);

    // ���������� � ��������� �����
    // �� ��������� ��� ��� �� ����� �� ���������� �������� ==
    if(chosenCard.rank == winnerCard.rank &&
       chosenCard.suit == winnerCard.suit)
       {
           cout << "�����! ��� ��������! \n";
       }
       else
       {
           cout << "���������! ��� ������! \n";
       }
}

int main()
{
    // ������ �� ���: ���� �� �����
    playGame();

    return 0;
}
