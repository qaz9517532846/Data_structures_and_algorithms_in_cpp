# 定義編譯器
CXX = g++

# 編譯選項
CXXFLAGS = -Wall -std=c++11

# 定義源文件和目標檔案
SRC = string_list.cpp StringLinkedList.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = test

# 編譯規則
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# 將 .cpp 轉換為 .o
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# 清理生成的檔案
clean:
	rm -f $(OBJ) $(TARGET)