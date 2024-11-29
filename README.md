## Build in macOS and Linux
>[!NOTE]
>
> я вам ни чем не помогу, могу дать только список нужных библиотек:
> glew, glfw, opengl32, glm, stb, nlohmann


## Build in Windows
>[!NOTE]
> Рекомендую:
>
>Visual Studio

```sh
открываем проект в VS (openGL.sln)
(в проекте все билиотеки настроены, поэтому от вас требуется только запустить)
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

## Список возможностей
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
> [!WARNING]
> ```sh
> файл должен иметь такую структуру
>
> 
> {
>  "название объекта": значениеТипа(int),
>}
> ```























