# 定義編譯器
CXX = g++

# 編譯選項
CXXFLAGS = -Wall -std=c++11

# 定義源文件和目標檔案（模板類不需要編譯 .cpp）
TARGET = HashDict

# 編譯規則：只編譯測試文件
$(TARGET): HashDict_test.cpp HashDict.cpp ../HashMap/HashMap.cpp
	$(CXX) $(CXXFLAGS) HashDict_test.cpp HashDict.cpp ../HashMap/HashMap.cpp -o $(TARGET)

# 將 .cpp 轉換為 .o
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# 清理生成的檔案
clean:
	rm -f $(OBJ) $(TARGET)
