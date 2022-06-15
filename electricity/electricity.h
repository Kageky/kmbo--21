#pragma once
#include <string>

class Object;
	@@ -50,7 +50,7 @@ class Object {
    /// </summary>
    /// <param name="idx">Индекс полюса, от <c>0</c> до значения, возвращаемого <see cref="getPoleCount()"/>.</param>
    /// <returns>Полюс с указанным индексом, или <c>nullptr</c>, если такой полюс не существует.</returns>
    Pole* getPole(size_t idx);

    /// <summary>
    /// Возвращает полюс по внутреннему индексу устройства.
	@@ -63,8 +63,7 @@ class Object {
    virtual ~Object() {}

    const std::string& getName() const { return name; }
    void getName(const std::string& newName) { name = newName; }
    /// <summary>
    /// Возвращает полюс по имени.
    /// </summary>
	@@ -96,22 +95,20 @@ class Object {
    /// <param name="poleName">Название подключаемого полюса текущего устройства</param>
    /// <param name="other">Устройство, которое связывается с текущим.</param>
    /// <param name="otherPoleName">Название подключаемого полюса другого устройства</param>
    /// <remarks>
    /// Может использоваться для связи устройства с самим собой.
    /// В этом случае в качестве <paramref name="other"/> следует передать то же устройство,
    /// для которого вызывается этот метод.
    /// </remarks>
    bool connect(const std::string& poleName, const Object& other, const std::string& otherPoleName);
    /// <резюме>
    /// Отключает указанный полюс, если к нему что-либо подключено.
    /// </summary>
    /// <param name="poleName">Название полюса, от которого производится отключение.</param>
    /// <returns><c>true</c> если что-либо было отключено, <c>false</c> в противном случае.</returns>
    /// <примечания>
    /// Вызов этого метода для полюса, если к нему ничего не подключено, не является ошибкой.
    /// </примечания>
    bool disconnect(const std::string& poleName);
};

	@@ -134,4 +131,32 @@ class Switch : public Object {

// TODO: класс светильника с двумя полюсами

class Light : public Object {
public:
    Pole a1, a2;

    Light(const std::string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};

// TODO: класс генератора с тремя полюсами (фаза, нейтраль, земпя).

class Generator : public Object {
public:
    Pole a1, a2, a3;

    Generator(const std::string& name = "");

    virtual size_t getPoleCount() const { return 3; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};
