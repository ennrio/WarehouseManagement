/****************************************************************************
** Meta object code from reading C++ file 'warehouse.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cpp/warehouse.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'warehouse.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9WarehouseE_t {};
} // unnamed namespace

template <> constexpr inline auto Warehouse::qt_create_metaobjectdata<qt_meta_tag_ZN9WarehouseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Warehouse",
        "productsChanged",
        "",
        "stockWarning",
        "message",
        "expirationWarning",
        "addProductFromQML",
        "id",
        "name",
        "category",
        "manufacturer",
        "quantity",
        "price",
        "expiryDate",
        "isPromotional",
        "isPerishable",
        "getProductByIndex",
        "Product*",
        "index",
        "getAllProductNames",
        "getProductsSimple",
        "QVariantList",
        "warehouseID",
        "address",
        "productCount",
        "capacity",
        "allProducts",
        "QList<QObject*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'productsChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stockWarning'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'expirationWarning'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Method 'addProductFromQML'
        QtMocHelpers::MethodData<void(const QString &, const QString &, const QString &, const QString &, int, double, const QString &, bool, bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 }, { QMetaType::QString, 9 }, { QMetaType::QString, 10 },
            { QMetaType::Int, 11 }, { QMetaType::Double, 12 }, { QMetaType::QString, 13 }, { QMetaType::Bool, 14 },
            { QMetaType::Bool, 15 },
        }}),
        // Method 'getProductByIndex'
        QtMocHelpers::MethodData<Product *(int)>(16, 2, QMC::AccessPublic, 0x80000000 | 17, {{
            { QMetaType::Int, 18 },
        }}),
        // Method 'getAllProductNames'
        QtMocHelpers::MethodData<QStringList() const>(19, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Method 'getProductsSimple'
        QtMocHelpers::MethodData<QVariantList() const>(20, 2, QMC::AccessPublic, 0x80000000 | 21),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'warehouseID'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'address'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'productCount'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'capacity'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'allProducts'
        QtMocHelpers::PropertyData<QList<QObject*>>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Warehouse, qt_meta_tag_ZN9WarehouseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Warehouse::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WarehouseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WarehouseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9WarehouseE_t>.metaTypes,
    nullptr
} };

void Warehouse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Warehouse *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->productsChanged(); break;
        case 1: _t->stockWarning((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->expirationWarning((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->addProductFromQML((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[6])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[9]))); break;
        case 4: { Product* _r = _t->getProductByIndex((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast<Product**>(_a[0]) = std::move(_r); }  break;
        case 5: { QStringList _r = _t->getAllProductNames();
            if (_a[0]) *reinterpret_cast<QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariantList _r = _t->getProductsSimple();
            if (_a[0]) *reinterpret_cast<QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Warehouse::*)()>(_a, &Warehouse::productsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Warehouse::*)(const QString & )>(_a, &Warehouse::stockWarning, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Warehouse::*)(const QString & )>(_a, &Warehouse::expirationWarning, 2))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->getWarehouseID(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->getAddress(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->getProductCount(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->getCapacity(); break;
        case 4: *reinterpret_cast<QList<QObject*>*>(_v) = _t->getAllProductsQML(); break;
        default: break;
        }
    }
}

const QMetaObject *Warehouse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Warehouse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9WarehouseE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Warehouse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Warehouse::productsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Warehouse::stockWarning(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Warehouse::expirationWarning(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
