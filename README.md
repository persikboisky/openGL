## Build in macOS and Linux
>[!NOTE]
>
> Я вам ни чем не помогу, могу дать только список нужных библиотек:
> glew, glfw, glm, stb, nlohmann, opengl32(Должна быть установлена по умолчанию драйвером)


## Build in Windows
>[!NOTE]
>[Библиотеки](https://github.com/persikboisky/libForOpengl)
>
> Рекомендую: Visual Studio

```sh
1. Скачиваем библиотеки по верхней ссылке
2. копируем папку lib в папку проекта(openGL)
3. открываем проект в VS (openGL.sln)
4. проверяем что бы сверху стояло Reales x64
5. запускаем
```
> [!WARNING]
>
> Проект настроен для сборки на winX64 и openGL 4.6

> [!TIP]
>
> ```sh
> Чтобы указать другую версию openGL заходим в файл Window.cpp (src/window/Window.cpp)
> Находим эти строки (они в начале), и указываем версию
> #define VERSION_MAJOR первое число
> #define VERSION_MINOR второе число
> ```

## Системы движка
>[!NOTE]
>```sh
> вся ниже предоставленная информация рассчитана на то, что вы будете использовать функции в main
> все функции имеют стиль записи (НазваниеСистемы::функция())
>```

## система Window
```sh
Window::initializateWindow(name, width, height) - Создаёт окно
name - заголовок окна(char*)
width - ширина окна(int)
height - высота окна(int)
```
```sh
Window::setWindowIcon(const char* path) - устанавливает иконку окна
принимает путь к png файлу

Window::terminate() - удаляет окно
Window::isCloseWindow() - возвращает true при закрытие окна

Window::setShouldClose(flag) - закрывает окно
если в flag передать true то окно закроется

Window::swapBuffer() - сменяет буфер

Window::width, Window::height - Эти переменные хранят соответственно ширину и высоту окна
```
> [!TIP]
> в openGL двойная буферизация, то есть на одном мы рисуем, а второй выводится на экран 

## Система Shader
```sh
shader::getShaderProgram(const char* frag, const char* vert);
возвращает дескриптор шейдерной программы и создаёт её, принимает путь к шейдерам

shader::select(unsigned int id) Принимает дескриптор шейд-граммы и выбирает её для работы
shader::use() включает выбранную программу

shader::setValueUniform(const float value, const char* name);
shader::setValueUniform(glm::mat4 matrix, const char* name);
обе функции имею одинаковые названия,
первая передаёт float значение в uniform переменную выбранного шейдера,
вторая передаёт матрицу в uniform переменную выбранного шейдера.
Принимают значение, название переменной в шейдере

shader::Delete(unsigned int id) удаляет шейдерную программу, принимает её дескриптор
```

## Система JSON
```sh
json::getValueFromJSON(const char* PATH, const char* object)
возвращает значение записанное в json, работает только с int переменными, принимает путь и название объекта

```
> [!NOTE]
> ```sh
> файл должен иметь такую структуру
>
> 
> {
>  "название объекта": значениеТипа(int),
>}
> ```

## Система VAO
```sh
vao::create(const std::vector<float>& data)
создаёт vao, возвращает дескриптор vao, принимает вектор вершин(одна вершина имеет кординаты(x, y, z, u, v))

vao::bind(unsigned int id)
Выбирает vao, принимает дискриптор

vao::DrawArrays(unsigned int mode, int first, unsigned int count);
Рисует выбранный vao, принимает вид примитива, начальную вершину, конечную

vao::deBind(); выключает vao
vao::Delete(unsigned int id); Удаляет vao, принимает дискриптор
```

## Система Event
```sh
Event::Init(); Включает систему evеnt
Event::isCloseWindow(); Проверяет окно на закрытие и возвращает true если поступила команда закрытия окна
Event::update() - обновляет буфер эвентов (проверяет эвенты)

Event::Mouse::GetMouseCordY() - возвращает позицию мышки по осиY
возвращает значение double

Event::Mouse::GetMouseCordX() - возвращает позицию мышки по осиX
возвращает значение double

Event::Mouse::GetMouseRightButton()
возвращает true если нажать на правую кнопку мыши

Event::Mouse::GetMouseLeftButton()
возвращает true если нажать на левую кнопку мыши

Event::Key::init(); Включает систему клавиш
Event::Key::getKey(int keyCode); возвращает true если клавиша нажата, и false если отпущена, принимает код клавиш
```

## Система PNG
```sh
png::loadPNG(const char* PATH);
принимае путь к png изображению, возвращает строку этого изображения

png::width, png::height, png::channels;
хранят ширину, высоту, кол-во каналов в изображении
```
> [!NOTE]
> при загрузки нового изображения, все переменные структуры png будут перезаписана

## Система Texture
```sh
texture::addTexture(unsigned char* texture, int width, int height, int channels);
Возвращает дискриптор png текстуры
Принимает код png текстуры
принимает ширину, высоты, кол-во каналов в текстуре

unsigned int loadText(const char* path);
Делает тоже самое что и верхняя функция, только проще 
Возвращает дискриптор, принимает путь к png файлу

texture::use(int n); - принимает номер текстуры
texture::useByID(unsigned int id); - принимает дискриптор тестуры
Одна и другая выбирают текстуру

texture::Delete(GLuint id); - удаляет по дискриптору текстуру
texture::allDelete(); - удаляет все текстуры
```

## Система Cursor
```sh
texture::setCursorMode(int mode); - Включает выбранный режим курсора
texture::showCursor(bool flag); - Делает курсор невидимым
texture::disableCursor(bool flag); - Выключает курсор
texture::setPosition(double x, double y); - Перемещает курсор в указанную позицию
```

> [!NOTE]
> В моём движке камера это набор функций для преобразование матриц,
> которые надо передавать в шейдер и умножать на вершины


## Система Camera
```sh
Camera название(glm::vec3 pos, float fov);
создаёт камеру, принимает позицию в виде vec3 и полезрение в виде float

название.rotate(float x, float y, float z); - Поворачивает камеру по указанным осям 
название.resetRotate(); - обнуляет матрицу поворота, это надо делать перед каждым поворотом камеры
название.move(float x, float y, float z); - Перемещает камеру по указанным осям и направлениям

название.getView(); - возвращаетВозвращает матрицу вида камеры
название.getProj(); - Возвращает матрицу проекции камеры
```













