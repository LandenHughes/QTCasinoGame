#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <QVector>
#include "card.h"

class FieldModel
{
public:
    FieldModel();

protected:
    //Does the player have insurance?
    int isInsured;
    //How many chips the player has altogether.
    int playerChips;
    //How many chips the player has bet this round.
    int betChips;
    //Determines wether or not the dealer's first card should be displayed or not.
    bool isDealerCardHidden;
    //The first card is the hidden card.
    QVector<Card> dealerHand;
    //Represents the hands of the player.  Needs to be layered like this to represent splits.
    QVector<QVector<Card>> playerHands;
};

#endif // FIELDMODEL_H
