## Build in macOS and Linux
>[!NOTE]
>
> я вам ни чем не помогу, могу дать только список нужных библиотек:
> glew, glfw, glm, stb, nlohmann, opengl32(должна устанавливаться с драйверами на гп)


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
> проект работает только на winX64 и openGL v4.6

> [!TIP]
>
> ```sh
> Чтобы указать другую версию openGL заходим в файл Window.cpp (src/window/Window.cpp)
> Находид эти строки (они в начале), и указываем версию
> #define VERSION_MAJOR первое число
> #define VERSION_MINOR второе число
> ```

## Системы движка
>[!NOTE]
>```sh
> вся ниже предоставленная информация расчитана на то, что вы будете использовать функции в main
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
Window::terminate() - удоляет окно
Window::isCloseWindow() - возращает true при закрытие окна

Window::setShouldClose(flag) - закрывает окно
если в flag передать true то окно закроется

Window::swapBuffer() - сменяет буфер
```
> [!TIP]
> в openGL двойная буфиризация, тоесть на одном мы рисуем, а второй выводится на экран 

## Система Shader
```sh
CreateShaderProgram::CreateShaderProgram названиеШейдернойПрограммы(const char* vert, const char* frag)
этот конструктор создаёт шейдерную программу, в него мы передаём путь к вершиному и фрагментному шейдеру

названиеШейдернойПрограммы.use() - включает шейдерную программу
названиеШейдернойПрограммы.delete() - удаляет шейдерную программу

названиеШейдернойПрограммы.setValueUniformF(const float value, const char* name)
передаёт значение в uniform переменную в шейдере(значение(float), имя uniform переменной(string))

```

## Система JSON
```sh
JSON::getValueFromJSON(const char* PATH, const char* object)
возврощает значение записанное в json работает только с int, принимает путь и название объекта

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
VAO название; - создаёт vao объект с укзаным названием

название.bind() - включает vao
название.debind() - выключает vao

addVBO({
кординаты вершин
}) - добавляет vbo в vao

название.draw(кол-во вершин) - ресует треуголник(и)
3 вершины - один треугольник
6 вершин - два треугольника
и тд.
```

## Система Event
```sh
Event::update() - обновляет буфер эвентов (проверяет эвенты)

Event::Mouse::GetMouseCordY() - возращант позицию мышки по осиY
возвращает значение double

Event::Mouse::GetMouseCordX() - возращант позицию мышки по осиX
возвращает значение double

Event::Mouse::GetMouseRightButton()
возвращает true если нажать на правую кнопку мыши

Event::Mouse::GetMouseLeftButton()
возвращает true если нажать на левую кнопку мыши
```




















