#ifndef CONVEYER_H
#define CONVEYER_H

#include <QVector>
#include <QQueue>

class Conveyer {

    friend std::ostream& operator<< (std::ostream &out, const Conveyer &conveyer);

    public:
        Conveyer();

        void loadRandomValuesInConveyer();

        int PushA(int inputNumber);
        int PushB(int inputNumber);

    private:
        QVector<int> amountsOfElementsBetweenNodesInQueueA;
        QVector<int> amountsOfElementsBetweenNodesInQueueB;

        QVector<QQueue<int>> partsOfQueueA;
        QVector<QQueue<int>> partsOfQueueB;

        QVector<int> valuesInNodes;

        int getRandomFrom0To9() const;
        int pushAnyQueue(QVector<QQueue<int>> &partsOfQueue, int inputNumber);
};

#endif // CONVEYER_H
