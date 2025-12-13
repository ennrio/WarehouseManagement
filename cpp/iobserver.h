#pragma once
#include <QString>

// Паттерн Observer: интерфейс наблюдателя
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const QString& message) = 0;
};
