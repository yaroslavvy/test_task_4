#include "conveyer.h"
#include <ctime>
#include <iostream>

Conveyer::Conveyer()
{
    amountsOfElementsBetweenNodesInQueueA = {3, 8, 9, 8};//structure of queue A could be specified from the console, if necessary
    amountsOfElementsBetweenNodesInQueueB = {2, 9, 8, 8};//structure of queue B could be specified from the console, if necessary
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Conveyer::loadRandomValuesInConveyer() {
//    if (amountsOfElementsBetweenNodesInQueueA.size() != amountsOfElementsBetweenNodesInQueueB.size()) {
//        throw exception("amounts of parts of queues A and B between nodes aren't equal!");
//    }
    for(auto amountOfElements : amountsOfElementsBetweenNodesInQueueA) {
        QQueue<int> queue;
        for (int i = 0; i < amountOfElements; ++i) {
            queue.enqueue(getRandomFrom0To9());
        }
        partsOfQueueA.push_back(queue);
    }

    for(auto amountOfElements : amountsOfElementsBetweenNodesInQueueB) {
        QQueue<int> queue;
        for (int i = 0; i < amountOfElements; ++i) {
            queue.enqueue(getRandomFrom0To9());
        }
        partsOfQueueB.push_back(queue);
    }

    for (int i = 0; i < amountsOfElementsBetweenNodesInQueueA.size(); ++i) {//so sizes of amountsOfElementsBetweenNodesInQueueA/B should be equal
        valuesInNodes.push_back(getRandomFrom0To9());
    }
}

int Conveyer::PushA(int inputNumber) {
    return pushAnyQueue(partsOfQueueA, inputNumber);
}

int Conveyer::PushB(int inputNumber) {
    return pushAnyQueue(partsOfQueueB, inputNumber);
}

int Conveyer::pushAnyQueue(QVector<QQueue<int>> &partsOfQueue, int inputNumber) {
    int popedValue = valuesInNodes.last();
    for (auto iter = partsOfQueue.begin(); iter != partsOfQueue.end(); ++iter) {
        if (iter == partsOfQueue.begin()){
            iter->enqueue(inputNumber);
        }
        else {
            iter->enqueue(valuesInNodes.at(iter - partsOfQueue.begin() - 1));
        }
    }
    for (auto iter = valuesInNodes.begin(); iter != valuesInNodes.end(); ++iter) {
        *iter = (partsOfQueue.begin() + (iter - valuesInNodes.begin()))->dequeue();
    }
    return popedValue;
}

int Conveyer::getRandomFrom0To9() const {
    return rand() % 10;
}

std::ostream& operator<< (std::ostream &out, const Conveyer &conveyer) {
    QVector<int> maxAmountsOfElementsBetweenNodesInQueuesAAndB;
    for (int i = 0; i < conveyer.amountsOfElementsBetweenNodesInQueueA.size(); ++i) {
        maxAmountsOfElementsBetweenNodesInQueuesAAndB.push_back(std::max(conveyer.amountsOfElementsBetweenNodesInQueueA.at(i), conveyer.amountsOfElementsBetweenNodesInQueueB.at(i)));
    }

    out << "A -> ";
    for (int i = 0; i < conveyer.partsOfQueueA.size(); ++i) {
        for (auto rIter = conveyer.partsOfQueueA.at(i).rbegin(); rIter != conveyer.partsOfQueueA.at(i).rend(); ++rIter) {
                    if((rIter == conveyer.partsOfQueueA.at(i).rbegin()) && (i > 0)){
                        out << " /";
                    }
                    out << QString::number(*rIter).toStdString();
                    if(rIter == conveyer.partsOfQueueA.at(i).rend() - 1){
                        std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueA.at(i)) * 2), ' ');
                        out << filling << "\\";
                    }
                    else {
                        out << "-";
                    }
                }
        if((++i) < conveyer.partsOfQueueB.size()){
            for (auto rIter = conveyer.partsOfQueueB.at(i).rbegin(); rIter != conveyer.partsOfQueueB.at(i).rend(); ++rIter) {
                if(rIter == conveyer.partsOfQueueB.at(i).rbegin()){
                    out << " /";
                }
                out << QString::number(*rIter).toStdString();
                if(rIter == conveyer.partsOfQueueB.at(i).rend() - 1){
                    std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueB.at(i)) * 2), ' ');
                    out << filling << "\\";
                }
                else {
                    out << "-";
                }
            }
        }
    }

    out << std::endl << "     ";

    for (int i = 0; i < conveyer.partsOfQueueA.size(); ++i) {
        for (auto rIter = conveyer.partsOfQueueA.at(i).rbegin(); rIter != conveyer.partsOfQueueA.at(i).rend(); ++rIter) {
                    if((rIter == conveyer.partsOfQueueA.at(i).rbegin()) && (i > 0)){
                        out << " ";
                    }
                    out << " ";
                    if(rIter == conveyer.partsOfQueueA.at(i).rend() - 1){
                        std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueA.at(i)) * 2), ' ');
                        out << filling << " " << conveyer.valuesInNodes.at(i);
                    }
                    else {
                        out << " ";
                    }
                }
        if((++i) < conveyer.partsOfQueueB.size()){
            for (auto rIter = conveyer.partsOfQueueB.at(i).rbegin(); rIter != conveyer.partsOfQueueB.at(i).rend(); ++rIter) {
                if(rIter == conveyer.partsOfQueueB.at(i).rbegin()){
                    out << " ";
                }
                out << " ";
                if(rIter == conveyer.partsOfQueueB.at(i).rend() - 1){
                    std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueB.at(i)) * 2), ' ');
                    out << filling << " " << conveyer.valuesInNodes.at(i);
                }
                else {
                    out << " ";
                }
            }
        }
    }

    out << std::endl << "B -> ";

    for (int i = 0; i < conveyer.partsOfQueueB.size(); ++i) {
        for (auto rIter = conveyer.partsOfQueueB.at(i).rbegin(); rIter != conveyer.partsOfQueueB.at(i).rend(); ++rIter) {
            if((rIter == conveyer.partsOfQueueB.at(i).rbegin()) && (i > 0)){
                out << " \\";
            }
            out << QString::number(*rIter).toStdString();
            if(rIter == conveyer.partsOfQueueB.at(i).rend() - 1){
                std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueB.at(i)) * 2), ' ');
                out << filling << "/";
            }
            else {
                out << "-";
            }
        }
        if((++i) < conveyer.partsOfQueueA.size()){
            for (auto rIter = conveyer.partsOfQueueA.at(i).rbegin(); rIter != conveyer.partsOfQueueA.at(i).rend(); ++rIter) {
                if(rIter == conveyer.partsOfQueueA.at(i).rbegin()){
                    out << " \\";
                }
                out << QString::number(*rIter).toStdString();
                if(rIter == conveyer.partsOfQueueA.at(i).rend() - 1){
                    std::string filling(static_cast<unsigned int>((maxAmountsOfElementsBetweenNodesInQueuesAAndB.at(i) - conveyer.amountsOfElementsBetweenNodesInQueueA.at(i)) * 2), ' ');
                    out << filling << "/";
                }
                else {
                    out << "-";
                }
            }
        }
    }
    return out;
}
