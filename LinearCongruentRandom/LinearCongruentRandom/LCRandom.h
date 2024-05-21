#ifndef LCRandom_H
#define LCRandom_H

#define DLLFunc extern "C" __declspec(dllexport)

typedef long long Int64;

typedef long Int32;


//随机数生成器的核心结构
struct RandomValue
{
	Int64 seed;
};


//获取当前随机种子
DLLFunc Int64 getSeed(const RandomValue* value);

//设置随机种子
DLLFunc void setSeed(RandomValue* value, const Int64 seed);

//推进随机数生成器并返回一个64位整型随机数，范围在[0,9223372036854775807)
DLLFunc Int64 NextInt64(RandomValue* value);

//推进随机数生成器并返回一个32位整型随机数，范围在[0,2147483647)
DLLFunc Int32 NextInt32(RandomValue* value);

//推进随机数生成器并返回一个随机双浮点数，范围在[0,1)
DLLFunc double NextDouble(RandomValue* value);

//推进随机数生成器并返回一个随机浮点数，范围在[0,1)
DLLFunc float NextFloat(RandomValue* value);


//推进随机数生成器并返回一个32位整型随机数，范围在[min,max)
DLLFunc Int32 NextInt32Range(RandomValue* value, Int32 min, Int32 max);


//推进随机数生成器并返回一个64位整型随机数，范围在[min,max)
DLLFunc Int64 NextInt64Range(RandomValue* value, Int64 min, Int64 max);

#endif // !LCRandom_H
