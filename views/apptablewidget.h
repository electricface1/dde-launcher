#ifndef APPTABLEWIDGET_H
#define APPTABLEWIDGET_H

#include "basetablewidget.h"
#include "fwd.h"
#include "dbusinterface/dbustype.h"

class QWheelEvent;
class AppItem;

class AppTableWidget : public BaseTableWidget
{
    Q_OBJECT
public:
    explicit AppTableWidget(QWidget *parent = 0);
    ~AppTableWidget();

    void initConnect();
    void setGridParameter(int column, int girdWidth, int itemWidth);

signals:

public slots:
    void addItem(ItemInfo itemInfo, int index);
    void addItems(const QList<ItemInfo>& itemInfos);

    void setItemInfosMap(const QMap<QString, ItemInfo>& itemInfos);

    void setAppNameItemInfoList(const QList<ItemInfo>& infoList);
    void setInstallTimeItemInfoList(const QList<ItemInfo>& infoList);
    void setuseFrequencyItemInfoList(const QList<ItemInfo>& infoList);
    void showSearchResult(const QList<ItemInfo>& infoList);

    void showbyName();
    void showByInstalledTime();
    void showByFrequency();
    void showBySortedMode(int mode);
    void showNormalMode();

    void openCheckedApp();

    void showAutoStartLabel(QString appKey);
    void hideAutoStartLabel(QString appKey);

protected:
    void wheelEvent(QWheelEvent* event);

private:
    int m_column;
    int m_gridWidth;
    int m_itemWidth;
    int m_currentMode;
    QMap<QString, ItemInfo> m_itemInfosMap;

    QList<ItemInfo> m_appNameItemInfoList;
    QList<ItemInfo> m_InstalltimeItemInfoList;
    QList<ItemInfo> m_useFrequencyItemInfoList;

    QMap<QString, AppItem*> m_appItems;
};

#endif // APPTABLEWIDGET_H