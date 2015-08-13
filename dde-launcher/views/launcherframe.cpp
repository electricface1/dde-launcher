#include "launcherframe.h"
#include "widgets/util.h"
#include "displaymodeframe.h"
#include "apptablewidget.h"
#include "categoryframe.h"
#include "navigationbar.h"
#include "app/global.h"
#include "Logger.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStackedLayout>
#include <QHBoxLayout>

LauncherFrame::LauncherFrame(QWidget *parent) : QFrame(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState(Qt::WindowFullScreen);
    setFixedSize(qApp->desktop()->screenGeometry().size());
    setObjectName("LauncherFrame");
    computerGrid(160, 60, 24, 160);
    initUI();
    initConnect();
    setStyleSheet(getQssFromFile(":/skin/qss/main.qss"));
}


void LauncherFrame::initUI(){
    m_categoryFrame = new CategoryFrame(this);
    m_categoryFrame->initUI(m_leftMargin, m_rightMargin, m_column, m_itemWidth, m_gridwidth);

    QFrame* appBox = new QFrame;
    appBox->setObjectName("AppBox");
    m_appTableWidget = new AppTableWidget(this);
    m_appTableWidget->setGridParameter(m_column, m_gridwidth, m_itemWidth);

    QHBoxLayout* appLayout = new QHBoxLayout(appBox);
    appLayout->addWidget(m_appTableWidget);
    appLayout->setContentsMargins(m_leftMargin, m_topMargin, m_rightMargin, m_bottomMargin);
    appBox->setLayout(appLayout);

    m_layout = new QStackedLayout(this);
    m_layout->addWidget(m_categoryFrame);
    m_layout->addWidget(appBox);
    m_layout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_layout);
    m_layout->setCurrentIndex(0);
    m_displayModeFrame = new DisplayModeFrame(this);
}

void LauncherFrame::computerGrid(int minimumLeftMargin, int minimumTopMargin, int miniSpacing, int itemWidth){
    int desktopWidth = qApp->desktop()->screenGeometry().width();
    int desktopHeight = qApp->desktop()->screenGeometry().height();
    m_itemWidth = itemWidth;
    m_column = (desktopWidth - minimumLeftMargin * 2) / (itemWidth + miniSpacing);
    m_spacing = (desktopWidth  - minimumLeftMargin * 2) / m_column - itemWidth;
    m_gridwidth = m_spacing + itemWidth;
    m_leftMargin = (desktopWidth - m_column * m_gridwidth)/ 2;
    m_rightMargin = desktopWidth - m_leftMargin - m_column * m_gridwidth;

    m_row = (desktopHeight - minimumTopMargin) / m_gridwidth;
    m_topMargin = (desktopHeight - m_row * m_gridwidth) / 2;
    m_bottomMargin = desktopHeight - m_row * m_gridwidth - m_topMargin;
    LOG_INFO() << m_column << m_itemWidth << m_spacing << m_leftMargin << m_rightMargin;
    LOG_INFO() << m_row << m_topMargin << m_bottomMargin;
}


void LauncherFrame::initConnect(){
    connect(m_displayModeFrame, SIGNAL(visibleChanged(bool)), this, SLOT(toggleDisableNavgationBar(bool)));
    connect(m_displayModeFrame, SIGNAL(sortModeChanged(int)), this, SLOT(showAppTableWidgetByMode(int)));
    connect(m_displayModeFrame, SIGNAL(categoryModeChanged(int)), this, SLOT(showNavigationBarByMode(int)));
}


void LauncherFrame::toggleDisableNavgationBar(bool flag){
    m_categoryFrame->getNavigationBar()->setDisabled(flag);
}

void LauncherFrame::showAppTableWidgetByMode(int mode){
    m_layout->setCurrentIndex(1);
    m_displayModeFrame->raise();
    emit signalManager->sortModeChanged(mode);
}

void LauncherFrame::showNavigationBarByMode(int mode){
    m_layout->setCurrentIndex(0);
    m_displayModeFrame->raise();

    if (mode == 1){
        m_categoryFrame->getNavigationBar()->setCurrentIndex(0);
    }else if (mode == 2){
        m_categoryFrame->getNavigationBar()->setCurrentIndex(1);
    }
}

void LauncherFrame::mouseReleaseEvent(QMouseEvent *event){

}

void LauncherFrame::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape){
        close();
    }
}

LauncherFrame::~LauncherFrame()
{

}
