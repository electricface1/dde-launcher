#include "logmanager.h"
#include "widgets/util.h"
#include <Logger.h>
#include <ConsoleAppender.h>
#include <RollingFileAppender.h>

LogManager::LogManager()
{
    m_format = "%{time}{dd-MM-yyyy, HH:mm:ss.zzz} [%{type:-7}] [%{file:-25} %{line}] %{message}\n";
}

void LogManager::initConsoleAppender(){
    m_consoleAppender = new ConsoleAppender;
    m_consoleAppender->setFormat(m_format);
    logger->registerAppender(m_consoleAppender);
}

void LogManager::initRollingFileAppender(){
    QString cachePath = QStandardPaths::standardLocations(QStandardPaths::CacheLocation).at(0);
    if (!QDir(cachePath).exists()){
        QDir(cachePath).mkpath(cachePath);
    }
    m_logPath = joinPath(cachePath, QString("launcher.log"));
    m_rollingFileAppender = new RollingFileAppender(m_logPath);
    m_rollingFileAppender->setFormat(m_format);
    m_rollingFileAppender->setLogFilesLimit(5);
    m_rollingFileAppender->setDatePattern(RollingFileAppender::DailyRollover);
    logger->registerAppender(m_rollingFileAppender);
}

LogManager::~LogManager()
{

}