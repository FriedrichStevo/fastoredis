#pragma once

#include <QStringList>

#include "global/types.h"

#include "common/patterns/singleton_pattern.h"

#include "core/connection_settings.h"

namespace fastoredis
{
    class SettingsManager
            : public common::patterns::LazySingleton<SettingsManager>
    {
    public:
        typedef std::vector<IConnectionSettingsBaseSPtr> ConnectionSettingsContainerType;
        friend class common::patterns::LazySingleton<SettingsManager>;

        void setDefaultView(supportedViews view);
        supportedViews defaultView() const;

        QString currentStyle() const;
        void setCurrentStyle(const QString &style);

        QString currentLanguage() const;
        void setCurrentLanguage(const QString &lang);

        void addConnection(IConnectionSettingsBaseSPtr connection);
        void removeConnection(IConnectionSettingsBaseSPtr connection);

        ConnectionSettingsContainerType connections() const;

        void addRConnection(const QString& connection);
        void removeRConnection(const QString& connection);
        QStringList recentConnections() const;

        bool syncTabs() const;
        void setSyncTabs(bool sync);

        void setLoggingDirectory(const QString& dir);
        QString loggingDirectory() const;

        bool autoCheckUpdates() const;
        void setAutoCheckUpdates(bool isCheck);

    private:
        void load();
        void save();

        SettingsManager();
        ~SettingsManager();

        supportedViews views_;
        QString curStyle_;
        QString curLanguage_;
        ConnectionSettingsContainerType connections_;
        QStringList recentConnections_;
        bool syncTabs_;
        QString loggingDir_;
        bool autoCheckUpdate_;
    };
}
