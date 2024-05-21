#include "pch.h"

//const long M = 1103515245;
//const long G = 32767;

#define M 1103515245

#define G 32767


Int64 getSeed(const RandomValue* value) {
	return value->seed;
}

void setSeed(RandomValue* value, const Int64 seed) {
	value->seed = seed;
}

Int64 NextInt64(RandomValue* value) {

	value->seed = (value->seed * M) + G;
	if (value->seed < 0)return value->seed & 0x7FFFFFFFFFFFFFFF;
	return value->seed;
}

Int32 NextInt32(RandomValue* value) {

	return (Int32)(NextInt64(value) % 2147483647);
}

double NextDouble(RandomValue* value) {

	return (double)NextInt32(value) / 2147483647.0;
}

float NextFloat(RandomValue* value) {

	return (float)NextDouble(value);
}


Int32 NextInt32Range(RandomValue* value, Int32 min, Int32 max) {

	return (Int32)(min + (NextInt64(value) % ((Int64)max - min)));
}


Int64 NextInt64Range(RandomValue* value, Int64 min, Int64 max) {

	return (min + (NextInt64(value) % ((Int64)max - min)));
}

