import asyncio
import time


async def async_wait(t):
    await asyncio.sleep(t)
    print(t)
    return t


async def main():
    tasks = [async_wait(3), async_wait(1), async_wait(2)]
    res = await asyncio.gather(*tasks)
    return res


if __name__ == "__main__":
    stime = time.time()
    loop = asyncio.get_event_loop()
    res = loop.run_until_complete(main())
    print(res)
    etime = time.time()
    print("ets:", etime - stime)

# output:
# 1
# 2
# 3
# [3, 1, 2]
# ets: 3.0018365383148193
