#include <memory>
#include <iostream>

int main(void)
{
    // not recommended
    // see make_unique for more details
    const auto uptr = std::unique_ptr<int>{new int(0)};

    // not recommended
    // see make_shared for more details
    const auto sptr1 = std::shared_ptr<int>{new int(0)};
    const auto sptr2 = std::shared_ptr<int>{sptr1};

    // weak pointer (no ownership)
    const auto wptr = std::weak_ptr<int>{sptr1};

    std::weak_ptr<int> wptr3;
    {
        const auto sptr3 = std::shared_ptr<int>(new int(0));
        wptr3 = sptr3;
    }

    if (const auto sptr3 = wptr3.lock(); sptr3){
        std::cout << "Successfully access sptr3" << std::endl;
    } else {
        std::cout << "sptr3 expired" << std::endl;
    }

    return 0;
}
