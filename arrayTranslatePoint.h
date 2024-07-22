// 包装函数，将不同大小的二维数组转换为 int**
template<typename Func, typename A, typename B>
auto wrap(Func func, A* a, B* b) {
  return [func, a, b](int** pa, int** pb) {
    func(reinterpret_cast<A*>(pa), reinterpret_cast<B*>(pb));
    };
}
// 包装函数，将不同大小的三维数组转换为 int***
template<typename Func, typename A, typename B>
auto wrap(Func func, A* a, B* b) {
    return [func, a, b](int*** pa, int*** pb) {
        func(reinterpret_cast<A*>(pa), reinterpret_cast<B*>(pb));
    };
}

int main1() {
    std::set<std::function<void(int**, int**)>> setTemp;

    // 添加包装后的函数到集合中
    setTemp.insert(wrap(func_Test, (int(*)[5])nullptr, (int(*)[4])nullptr));
    setTemp.insert(wrap(func_Test1, (int(*)[1])nullptr, (int(*)[2])nullptr));

    // 创建测试数组
    int a1[5][5] = {0};
    int b1[5][4] = {0};
    int a2[1][1] = {0};
    int b2[1][2] = {0};

    // 将数组转换为 int**
    int* pa1[5] = {a1[0], a1[1], a1[2], a1[3], a1[4]};
    int* pb1[4] = {b1[0], b1[1], b1[2], b1[3]};
    int* pa2[1] = {a2[0]};
    int* pb2[2] = {b2[0], b2[1]};

    // 从集合中调用函数
    for (const auto& func : setTemp) {
        func(pa1, pb1); // 此调用适用于 func_Test
        func(pa2, pb2); // 此调用适用于 func_Test1
    }

    return 0;
}

int main2() {
    std::set<std::function<void(int***, int***)>> setTemp;

    // 添加包装后的函数到集合中
    setTemp.insert(wrap(func_Test, (int(*)[5][3])nullptr, (int(*)[4][2])nullptr));
    setTemp.insert(wrap(func_Test1, (int(*)[1][1])nullptr, (int(*)[2][2])nullptr));

    // 创建测试数组
    int a1[2][5][3] = {{{0}}};
    int b1[2][4][2] = {{{0}}};
    int a2[2][1][1] = {{{0}}};
    int b2[2][2][2] = {{{0}}};

    // 将数组转换为 int***
    int** pa1[2];
    for (int i = 0; i < 2; ++i) {
        pa1[i] = reinterpret_cast<int**>(a1[i]);
    }

    int** pb1[2];
    for (int i = 0; i < 2; ++i) {
        pb1[i] = reinterpret_cast<int**>(b1[i]);
    }

    int** pa2[2];
    for (int i = 0; i < 2; ++i) {
        pa2[i] = reinterpret_cast<int**>(a2[i]);
    }

    int** pb2[2];
    for (int i = 0; i < 2; ++i) {
        pb2[i] = reinterpret_cast<int**>(b2[i]);
    }

    // 从集合中调用函数
    for (const auto& func : setTemp) {
        func(reinterpret_cast<int***>(pa1), reinterpret_cast<int***>(pb1)); // 此调用适用于 func_Test
        func(reinterpret_cast<int***>(pa2), reinterpret_cast<int***>(pb2)); // 此调用适用于 func_Test1
    }

    return 0;
}

