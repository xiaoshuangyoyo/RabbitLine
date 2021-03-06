//
// Created by NorSnow_ZJ on 2018/9/25.
//

#include "rabbitline.h"

using namespace RabbitLine;

int64_t RabbitLine::create(Func func)
{
    Scheduler * sc = getLocalScheduler();
    return sc->create(func);
}

void RabbitLine::resume(int64_t id)
{
    Scheduler * sc = getLocalScheduler();
    sc->resume(id);
}

int64_t RabbitLine::getMyCoId()
{
    Scheduler * sc = getLocalScheduler();
    return sc->getRunningWoker();
}

void RabbitLine::yield()
{
    Scheduler * sc = getLocalScheduler();
    sc->yield();
}

void RabbitLine::eventLoop()
{
    Scheduler * sc = getLocalScheduler();
    sc->mainLoop();
}

void RabbitLine::stopLoop()
{
    Scheduler * sc = getLocalScheduler();
    sc->stopLoop();
}

int64_t RabbitLine::addTimer(Timestamp expirationTime, TimeoutCallbackFunc callback, bool repeat, int interval)
{
    Poller * po = getLocalPoller();
    return po->addTimer(expirationTime, callback, repeat, interval);
}

void  RabbitLine::removeTimer(int64_t seq)
{
    Poller * po = getLocalPoller();
    po->removeTimer(seq);
}

