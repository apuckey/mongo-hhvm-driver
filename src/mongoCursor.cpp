#include <iostream>
#include "ext_mongo.h"

namespace HPHP {

const StaticString
  s_mongocursor("MongoCursor"),
  s_mongoc_cursor("__mongoc_cursor");

////////////////////////////////////////////////////////////////////////////////

static Resource get_cursor_resource(Object obj) {
  auto res = obj->o_realProp(s_mongoc_cursor, ObjectData::RealPropUnchecked, s_mongocursor);

  if (!res || !res->isResource()) {
    return null_resource;
  }

  return res->toResource();
}

static MongocCursor *get_cursor(Object obj) {
  auto res = get_cursor_resource(obj);

  return res.getTyped<MongocCursor>(true, false);
}

////////////////////////////////////////////////////////////////////////////////
// class MongoCursor

static Object HHVM_METHOD(MongoCursor, addOption, const String& key, CVarRef value) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, awaitData, bool wait) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, batchSize, int64_t batchSize) {
  throw NotImplementedException("Batch Size");
}

static void HHVM_METHOD(MongoCursor, __construct, const Object& connection, const String& ns, const Array& query, const Array& fields) {
  //Note: all other parameter values are taken from https://github.com/mongodb/mongo-c-driver/blob/3104b0b2c6fce06c1fe0d87e2b3b7bd107574fc2/tests/test-mongoc-cursor.c#L81
  //TODO: you need to turn PHP values into BSON to construct the C cursor with query and project objects.
  //bson_append_value: https://github.com/mongodb/libbson/blob/d1559673630cd754f4da1f12d7e7f9796d7e5d95/tests/test-value.c#L73
  //bson_append_utf8

  //build bson object for query (currently allow only string-string key-value pairs)
  bson_t query_bs;
  bson_init(&query_bs);
  bson_append_utf8(&query_bs, "test_field", 10, query[String("test_field")].toStrRef().c_str(), 1);
  //TODO: how to get the mongoc_client_t type object from connection?
  MongocCursor *cursor = new MongocCursor(connection.get(), ns, MONGOC_QUERY_NONE, 0, 1, 1, false, &query_bs, NULL, NULL);
  this_->o_set(s_mongoc_cursor, client, s_mongocursor);
  bson_destroy(&query_bs);
}

static int64_t HHVM_METHOD(MongoCursor, count, bool foundOnly) {
  throw NotImplementedException("Not Implemented");
}

static Array HHVM_METHOD(MongoCursor, current) {
  throw NotImplementedException("Not Implemented");
}

static bool HHVM_METHOD(MongoCursor, dead) {
  throw NotImplementedException("Not Implemented");
}

static void HHVM_METHOD(MongoCursor, doQuery) {
  throw NotImplementedException("Not Implemented");
}

static Array HHVM_METHOD(MongoCursor, explain) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, fields, CArrRef f) {
  throw NotImplementedException("Not Implemented");
}

static Array HHVM_METHOD(MongoCursor, getNext) {
  throw NotImplementedException("Not Implemented");
}

static Array HHVM_METHOD(MongoCursor, getReadPreference) {
  throw NotImplementedException("Not Implemented");
}

static bool HHVM_METHOD(MongoCursor, hasNext) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, hint, CVarRef index) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, immortal, bool liveForever) {
  throw NotImplementedException("Not Implemented");
}

static Array HHVM_METHOD(MongoCursor, info) {
  throw NotImplementedException("Not Implemented");
}

static String HHVM_METHOD(MongoCursor, key) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, limit, int64_t num) {
  throw NotImplementedException("Not Implemented");
}

static void HHVM_METHOD(MongoCursor, next) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, partial, bool okay) {
  throw NotImplementedException("Not Implemented");
}

static void HHVM_METHOD(MongoCursor, reset) {
  throw NotImplementedException("Not Implemented");
}

static void HHVM_METHOD(MongoCursor, rewind) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, setFlag, int64_t flag, bool set) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, setReadPreference, const String& read_preference, CArrRef tags) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, skip, int64_t num) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, slaveOkay, bool okay) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, snapshot) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, sort, CArrRef fields) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, tailable, bool tail) {
  throw NotImplementedException("Not Implemented");
}

static Object HHVM_METHOD(MongoCursor, timeout, int64_t ms) {
  throw NotImplementedException("Not Implemented");
}

static bool HHVM_METHOD(MongoCursor, valid) {
  throw NotImplementedException("Not Implemented");
}

////////////////////////////////////////////////////////////////////////////////

void mongoExtension::_initMongoCursorClass() {
    HHVM_ME(MongoCursor, addOption);
    HHVM_ME(MongoCursor, awaitData);
    HHVM_ME(MongoCursor, batchSize);
    HHVM_ME(MongoCursor, __construct);
    HHVM_ME(MongoCursor, count);
    HHVM_ME(MongoCursor, current);
    HHVM_ME(MongoCursor, dead);
    HHVM_ME(MongoCursor, doQuery);
    HHVM_ME(MongoCursor, explain);
    HHVM_ME(MongoCursor, fields);
    HHVM_ME(MongoCursor, getNext);
    HHVM_ME(MongoCursor, getReadPreference);
    HHVM_ME(MongoCursor, hasNext);
    HHVM_ME(MongoCursor, hint);
    HHVM_ME(MongoCursor, immortal);
    HHVM_ME(MongoCursor, info);
    HHVM_ME(MongoCursor, key);
    HHVM_ME(MongoCursor, limit);
    HHVM_ME(MongoCursor, next);
    HHVM_ME(MongoCursor, partial);
    HHVM_ME(MongoCursor, reset);
    HHVM_ME(MongoCursor, rewind);
    HHVM_ME(MongoCursor, setFlag);
    HHVM_ME(MongoCursor, setReadPreference);
    HHVM_ME(MongoCursor, skip);
    HHVM_ME(MongoCursor, slaveOkay);
    HHVM_ME(MongoCursor, snapshot);
    HHVM_ME(MongoCursor, sort);
    HHVM_ME(MongoCursor, tailable);
    HHVM_ME(MongoCursor, timeout);
    HHVM_ME(MongoCursor, valid);
}

} // namespace HPHP
