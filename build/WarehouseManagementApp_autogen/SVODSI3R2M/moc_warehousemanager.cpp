/****************************************************************************
** Meta object code from reading C++ file 'warehousemanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/warehousemanager.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehousemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN16WarehouseManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto WarehouseManager::qt_create_metaobjectdata<qt_meta_tag_ZN16WarehouseManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WarehouseManager",
        "warehousesChanged",
        "",
        "suppliersChanged",
        "employeesChanged",
        "notification",
        "message",
        "addWarehouse",
        "id",
        "address",
        "capacity",
        "getWarehouse",
        "Warehouse*",
        "getWarehouses",
        "QList<QObject*>",
        "addSupplier",
        "companyName",
        "contactInfo",
        "getSuppliers",
        "addEmployee",
        "name",
        "position",
        "getEmployees",
        "processSupply",
        "supplyID",
        "warehouseID",
        "generateReport",
        "Report*",
        "ReportFactory*",
        "factory",
        "reportID",
        "warehouses",
        "suppliers",
        "employees"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'warehousesChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suppliersChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'employeesChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'notification'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Method 'addWarehouse'
        QtMocHelpers::MethodData<void(const QString &, const QString &, int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::Int, 10 },
        }}),
        // Method 'getWarehouse'
        QtMocHelpers::MethodData<Warehouse *(const QString &)>(11, 2, QMC::AccessPublic, 0x80000000 | 12, {{
            { QMetaType::QString, 8 },
        }}),
        // Method 'getWarehouses'
        QtMocHelpers::MethodData<QList<QObject*>()>(13, 2, QMC::AccessPublic, 0x80000000 | 14),
        // Method 'addSupplier'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 16 }, { QMetaType::QString, 17 },
        }}),
        // Method 'getSuppliers'
        QtMocHelpers::MethodData<QList<QObject*>()>(18, 2, QMC::AccessPublic, 0x80000000 | 14),
        // Method 'addEmployee'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 20 }, { QMetaType::QString, 21 }, { QMetaType::QString, 17 },
        }}),
        // Method 'getEmployees'
        QtMocHelpers::MethodData<QList<QObject*>()>(22, 2, QMC::AccessPublic, 0x80000000 | 14),
        // Method 'processSupply'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 24 }, { QMetaType::QString, 25 },
        }}),
        // Method 'generateReport'
        QtMocHelpers::MethodData<Report *(ReportFactory *, const QString &)>(26, 2, QMC::AccessPublic, 0x80000000 | 27, {{
            { 0x80000000 | 28, 29 }, { QMetaType::QString, 30 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'warehouses'
        QtMocHelpers::PropertyData<QList<QObject*>>(31, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'suppliers'
        QtMocHelpers::PropertyData<QList<QObject*>>(32, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'employees'
        QtMocHelpers::PropertyData<QList<QObject*>>(33, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WarehouseManager, qt_meta_tag_ZN16WarehouseManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject WarehouseManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16WarehouseManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16WarehouseManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16WarehouseManagerE_t>.metaTypes,
    nullptr
} };

void WarehouseManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WarehouseManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->warehousesChanged(); break;
        case 1: _t->suppliersChanged(); break;
        case 2: _t->employeesChanged(); break;
        case 3: _t->notification((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->addWarehouse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 5: { Warehouse* _r = _t->getWarehouse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<Warehouse**>(_a[0]) = std::move(_r); }  break;
        case 6: { QList<QObject*> _r = _t->getWarehouses();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->addSupplier((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: { QList<QObject*> _r = _t->getSuppliers();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->addEmployee((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 10: { QList<QObject*> _r = _t->getEmployees();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->processSupply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: { Report* _r = _t->generateReport((*reinterpret_cast<std::add_pointer_t<ReportFactory*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<Report**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ReportFactory* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)()>(_a, &WarehouseManager::warehousesChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)()>(_a, &WarehouseManager::suppliersChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)()>(_a, &WarehouseManager::employeesChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)(const QString & )>(_a, &WarehouseManager::notification, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QObject*>*>(_v) = _t->getWarehouses(); break;
        case 1: *reinterpret_cast<QList<QObject*>*>(_v) = _t->getSuppliers(); break;
        case 2: *reinterpret_cast<QList<QObject*>*>(_v) = _t->getEmployees(); break;
        default: break;
        }
    }
}

const QMetaObject *WarehouseManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WarehouseManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16WarehouseManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WarehouseManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WarehouseManager::warehousesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WarehouseManager::suppliersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WarehouseManager::employeesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WarehouseManager::notification(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
