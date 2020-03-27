#include "Logger.hpp"

int     main(void){
    Logger      logger("test.log");

    logger.log("file", "user gvannest has finished exercice 9.");
    logger.log("console", "user gvannest has made a log on console");
    logger.log("file", "Error: Something is missing.");
    logger.log("console", "Error: a brain has been lost on console");
    logger.log("file", "Last try before true end.");
}