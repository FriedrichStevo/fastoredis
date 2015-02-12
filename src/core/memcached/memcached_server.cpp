#include "core/memcached/memcached_server.h"

#include "core/memcached/memcached_database.h"
#include "core/logger.h"

namespace fastoredis
{
    MemcachedServer::MemcachedServer(const IDriverSPtr& drv, bool isMaster)
        : IServer(drv,isMaster)
    {

    }

    IDatabaseSPtr MemcachedServer::createDatabaseImpl(DataBaseInfoSPtr info)
    {
        return IDatabaseSPtr(new MemcachedDatabase(shared_from_this(), info));
    }
}
