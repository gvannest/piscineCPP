#include "Asteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "MiningBarge.hpp"
#include "StripMiner.hpp"
#include "Comet.hpp"
#include "Asteroid.hpp"
#include <iostream>

int main(void) {
    DeepCoreMiner*  coreMiner1 = new DeepCoreMiner;
    StripMiner*  stripMiner1 = new StripMiner;

    DeepCoreMiner  coreMiner2 = *coreMiner1;
    StripMiner  stripMiner2 = *stripMiner1;
    StripMiner*  stripMiner3 = new StripMiner;

    Asteroid*   asteroid1 = new Asteroid;
    Asteroid   asteroid2 = *asteroid1;
    Comet *     comet1 = new Comet;
    Comet       comet2 = *comet1;

    MiningBarge* barge1 = new MiningBarge;

    barge1->equip(coreMiner1);
    barge1->equip(stripMiner1);
    barge1->equip(&coreMiner2);

    barge1->mine(asteroid1);
    std::cout << "----------------" << std::endl;
    barge1->mine(comet1);
    std::cout << "----------------" << std::endl;
    barge1->mine(&asteroid2);
    std::cout << "----------------" << std::endl;

    barge1->equip(&stripMiner2);
    barge1->equip(stripMiner3);

    MiningBarge barge2 = *barge1;

    barge2.mine(&comet2);
    std::cout << "----------------" << std::endl;

    delete coreMiner1;
    delete stripMiner1;
    delete stripMiner3;
    delete asteroid1;
    delete comet1;
    delete barge1;

    return 0;
}