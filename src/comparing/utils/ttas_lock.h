//
// Created by Helga on 2019-07-17.
//

#ifndef MUTUAL_EXCLUSION_TTAS_LOCK_H
#define MUTUAL_EXCLUSION_TTAS_LOCK_H


#include <atomic>

namespace utils {

    class TTASLock {
    public:
        TTASLock(void)
                : lock_(false) {}

        void Lock(void) {
            while(true) {
                while(atomic_load(&lock_)) {};
                if (!std::atomic_exchange(&lock_, true)) {
                    break;
                }
            }
        }

        void Unlock(void) {
            std::atomic_store(&lock_, false);
        }

    public:
        static constexpr auto name_ = "TTASLock";

    private:
        std::atomic<bool> lock_;
    };

} // namespace utils


#endif //MUTUAL_EXCLUSION_TTAS_LOCK_H
