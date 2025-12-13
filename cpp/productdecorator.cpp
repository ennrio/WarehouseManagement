#include "productdecorator.h"

ProductDecorator::ProductDecorator(Product* product, QObject* parent)
: Product(parent), m_wrappedProduct(product) {}

ProductDecorator::~ProductDecorator() {
    delete m_wrappedProduct;
}

QString ProductDecorator::getDetails() const {
    return m_wrappedProduct->getDetails();
}

bool ProductDecorator::checkExpiration() const {
    return m_wrappedProduct->checkExpiration();
}

void ProductDecorator::updateQuantity(int amount) {
    m_wrappedProduct->updateQuantity(amount);
}

double ProductDecorator::getUnitPrice() const
{
    return m_wrappedProduct->getUnitPrice();
}

QString ProductDecorator::getProductID() const {
    return m_wrappedProduct->getProductID();
}

QString ProductDecorator::getName() const {
    return m_wrappedProduct->getName();
}

int ProductDecorator::getQuantity() const {
    return m_wrappedProduct->getQuantity();
}

QDate ProductDecorator::getExpirationDate() const {
    return m_wrappedProduct->getExpirationDate();
}

QString ProductDecorator::getCategory() const
{
    return "";
}

QString ProductDecorator::getManufacturer() const
{
    return "";
}
