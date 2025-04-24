#include <iostream>
#include "test.pb.h"  // 包含生成的头文件

int main() {
    // 创建一个 TestMessage 对象
    TestMessage message;

    // 设置字段值
    message.set_message("Hello, Protocol Buffers!");
    message.set_id(42);

    // 打印消息内容
    std::cout << "Message: " << message.message() << std::endl;
    std::cout << "ID: " << message.id() << std::endl;

    // 将消息序列化到字符串
    std::string serialized_data;
    if (!message.SerializeToString(&serialized_data)) {
        std::cerr << "Failed to serialize message." << std::endl;
        return -1;
    }
    std::cout << "Serialized data: " << serialized_data << std::endl;

    // 反序列化消息
    TestMessage new_message;
    if (!new_message.ParseFromString(serialized_data)) {
        std::cerr << "Failed to parse message." << std::endl;
        return -1;
    }

    // 打印反序列化的消息内容
    std::cout << "Deserialized Message: " << new_message.message() << std::endl;
    std::cout << "Deserialized ID: " << new_message.id() << std::endl;

    return 0;
}
