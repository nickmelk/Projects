#include "dengine/diagnostic_engine.h"
#include "dengine/logger.h"
#include "dengine/sensor_reading.h"

int main()
{
    DiagnosticEngine engine {};
    CoolantTemperatureReading reading {130};

    engine.evaluate(reading);

    EventLogger logger {};

    logger.log(engine.event());
    logger.flog(engine.event(), "diagnostic.log");

    return 0;
}
