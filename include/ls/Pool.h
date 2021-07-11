#ifndef LS_POOL_H
#define LS_POOL_H

#include "queue"
#include "mutex"

namespace ls
{
	template<class T>
	class Pool
	{
		public:
			~Pool()
			{
				while(!pool.empty())
				{
					delete pool.front();
					pool.pop();
				}
			}

			void put(T* it)
			{
				std::lock_guard<std::mutex> poolLock(poolMutex);
				pool.push(it);	
			}

			T* get()
			{
				std::lock_guard<std::mutex> poolLock(poolMutex);
				if(pool.empty())
					return nullptr;
				auto it = pool.front();
				pool.pop();
				return it;
			}
		private:
			std::queue<T *> pool;
			std::mutex poolMutex;
	};
}

#endif
