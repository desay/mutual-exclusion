//
// Created by Helga on 2019-07-17.
//

#ifndef MUTUAL_EXCLUSION_TAS_LOCK_H
#define MUTUAL_EXCLUSION_TAS_LOCK_H


namespace utils {

    class TASLock {
    public:
        TASLock(void)
                : lock_(ATOMIC_FLAG_INIT) {}

        void Lock(void) {
            while(lock_.test_and_set());
        }

        void Unlock(void) {
            lock_.clear();
        }

    public:
        static constexpr auto name_ = "TASLock";

    private:
        std::atomic_flag lock_;
    };

} // namespace utils


#endif //MUTUAL_EXCLUSION_TAS_LOCK_H
