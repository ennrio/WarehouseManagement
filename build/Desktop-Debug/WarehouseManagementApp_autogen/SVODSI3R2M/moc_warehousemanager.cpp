/****************************************************************************
** Meta object code from reading C++ file 'warehousemanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cpp/warehousemanager.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehousemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
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
        "suppliesChanged",
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
        "createSupply",
        "supplierID",
        "date",
        "QVariantList",
        "products",
        "confirmSupply",
        "getSupplies",
        "getSupply",
        "Supply*",
        "generateReport",
        "Report*",
        "ReportFactory*",
        "factory",
        "reportID",
        "generateStockReport",
        "StockReport*",
        "warehouse",
        "reportId",
        "generateExpiredReport",
        "ExpiredReport*",
        "warehouses",
        "suppliers",
        "employees",
        "supplies"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'warehousesChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suppliersChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'employeesChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suppliesChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'notification'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'addWarehouse'
        QtMocHelpers::MethodData<void(const QString &, const QString &, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QString, 10 }, { QMetaType::Int, 11 },
        }}),
        // Method 'getWarehouse'
        QtMocHelpers::MethodData<Warehouse *(const QString &)>(12, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'getWarehouses'
        QtMocHelpers::MethodData<QList<QObject*>()>(14, 2, QMC::AccessPublic, 0x80000000 | 15),
        // Method 'addSupplier'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QString, 17 }, { QMetaType::QString, 18 },
        }}),
        // Method 'getSuppliers'
        QtMocHelpers::MethodData<QList<QObject*>()>(19, 2, QMC::AccessPublic, 0x80000000 | 15),
        // Method 'addEmployee'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QString, 21 }, { QMetaType::QString, 22 }, { QMetaType::QString, 18 },
        }}),
        // Method 'getEmployees'
        QtMocHelpers::MethodData<QList<QObject*>()>(23, 2, QMC::AccessPublic, 0x80000000 | 15),
        // Method 'processSupply'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 }, { QMetaType::QString, 26 },
        }}),
        // Method 'createSupply'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QVariantList &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 }, { QMetaType::QString, 28 }, { QMetaType::QString, 29 }, { 0x80000000 | 30, 31 },
        }}),
        // Method 'confirmSupply'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 25 }, { QMetaType::QString, 26 },
        }}),
        // Method 'getSupplies'
        QtMocHelpers::MethodData<QList<QObject*>()>(33, 2, QMC::AccessPublic, 0x80000000 | 15),
        // Method 'getSupply'
        QtMocHelpers::MethodData<Supply *(const QString &)>(34, 2, QMC::AccessPublic, 0x80000000 | 35, {{
            { QMetaType::QString, 25 },
        }}),
        // Method 'generateReport'
        QtMocHelpers::MethodData<Report *(ReportFactory *, const QString &)>(36, 2, QMC::AccessPublic, 0x80000000 | 37, {{
            { 0x80000000 | 38, 39 }, { QMetaType::QString, 40 },
        }}),
        // Method 'generateStockReport'
        QtMocHelpers::MethodData<StockReport *(Warehouse *, const QString &)>(41, 2, QMC::AccessPublic, 0x80000000 | 42, {{
            { 0x80000000 | 13, 43 }, { QMetaType::QString, 44 },
        }}),
        // Method 'generateExpiredReport'
        QtMocHelpers::MethodData<ExpiredReport *(Warehouse *, const QString &)>(45, 2, QMC::AccessPublic, 0x80000000 | 46, {{
            { 0x80000000 | 13, 43 }, { QMetaType::QString, 44 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'warehouses'
        QtMocHelpers::PropertyData<QList<QObject*>>(47, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'suppliers'
        QtMocHelpers::PropertyData<QList<QObject*>>(48, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'employees'
        QtMocHelpers::PropertyData<QList<QObject*>>(49, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 2),
        // property 'supplies'
        QtMocHelpers::PropertyData<QList<QObject*>>(50, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
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
        case 3: _t->suppliesChanged(); break;
        case 4: _t->notification((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->addWarehouse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[3]))); break;
        case 6: { Warehouse* _r = _t->getWarehouse((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<Warehouse**>(_a[0]) = std::move(_r); }  break;
        case 7: { QList<QObject*> _r = _t->getWarehouses();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->addSupplier((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        case 9: { QList<QObject*> _r = _t->getSuppliers();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->addEmployee((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4]))); break;
        case 11: { QList<QObject*> _r = _t->getEmployees();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->processSupply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->createSupply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QVariantList>>(_a[4]))); break;
        case 14: _t->confirmSupply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: { QList<QObject*> _r = _t->getSupplies();
            if (_a[0]) *reinterpret_cast<QList<QObject*>*>(_a[0]) = std::move(_r); }  break;
        case 16: { Supply* _r = _t->getSupply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<Supply**>(_a[0]) = std::move(_r); }  break;
        case 17: { Report* _r = _t->generateReport((*reinterpret_cast<std::add_pointer_t<ReportFactory*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<Report**>(_a[0]) = std::move(_r); }  break;
        case 18: { StockReport* _r = _t->generateStockReport((*reinterpret_cast<std::add_pointer_t<Warehouse*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<StockReport**>(_a[0]) = std::move(_r); }  break;
        case 19: { ExpiredReport* _r = _t->generateExpiredReport((*reinterpret_cast<std::add_pointer_t<Warehouse*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<ExpiredReport**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< ReportFactory* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Warehouse* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Warehouse* >(); break;
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
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)()>(_a, &WarehouseManager::suppliesChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (WarehouseManager::*)(const QString & )>(_a, &WarehouseManager::notification, 4))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
        case 3: *reinterpret_cast<QList<QObject*>*>(_v) = _t->getSupplies(); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
void WarehouseManager::suppliesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WarehouseManager::notification(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
