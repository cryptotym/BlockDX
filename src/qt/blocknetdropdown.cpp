// Copyright (c) 2018 The Blocknet Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "blocknetdropdown.h"

BlocknetDropdown::BlocknetDropdown(const QString &title, QWidget* parent) : QComboBox(parent) {
    this->setObjectName("dropdown");
    this->setFixedSize(180, 40);
    this->addItem("Test");
    this->addItem("Second");
    connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));
}

QVariant BlocknetDropdown::value() const {
    return itemData(currentIndex());
}

void BlocknetDropdown::setValue(const QVariant& value) {
    setCurrentIndex(findData(value));
}

void BlocknetDropdown::handleSelectionChanged(int /*idx*/) {
    emit valueChanged();
}
