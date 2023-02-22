#include <memory>
#include <iostream>

int main(void)
{
    // not recommended
    // see make_unique for more details
    auto uptr = std::unique_ptr<int>{new int(0)};

    // cannot copy because of exclusive ownership
    // const auto uptr2 = uptr;
    // can move (transfer of the ownership)
    const auto uptr2 = std::move(uptr);

    // not recommended
    // see make_shared for more details
    const auto sptr1 = std::shared_ptr<int>{new int(0)};

    // can copy/move - shared ownership
    const auto sptr2 = std::shared_ptr<int>{sptr1};

    // weak pointer (no ownership)
    // break cyclic references
    const auto wptr = std::weak_ptr<int>{sptr1};

    std::weak_ptr<int> wptr3;
    {
        const auto sptr3 = std::shared_ptr<int>(new int(0));
        wptr3 = sptr3;
    }

    // weak_ptr is a ticket that allows you to access the shared_ptr
    // useful for building a cache
    // See Herb Sutter's speech at CPPCON
    // https://www.youtube.com/watch?v=JfmTagWcqoE
    if (const auto sptr3 = wptr3.lock(); sptr3){
        std::cout << "Successfully access sptr3" << std::endl;
    } else {
        std::cout << "sptr3 expired" << std::endl;
    }

    return 0;
}
