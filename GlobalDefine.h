#ifndef GLOBALDEFINE_H
#define GLOBALDEFINE_H

// 定义右键菜单形式
enum class ChildRightKeyType {
    Normal, // 默认: 复制, 粘贴, 删除, 移至文件夹, 移至多项操作
    Folder, // 创建文件夹: 复制, 删除 (接受双击，切换页面)
    Goto, // 前往页面: 复制, 粘贴, 删除
    Jump, // 跳转页面: 复制, 粘贴, 删除
    MutilAction, // 多项式: 复制, 粘贴, 删除, 移到文件夹
    MutilActionSwitch, // 多项式操作切换: 复制, 粘贴, 删除, 移到文件夹
    Random, // 随机操作: 复制, 粘贴, 删除, 移到文件夹
    Clock, // 定时器: 复制, 粘贴, 删除, 移到文件夹
    HotKeySwitch, // 热荐切换:  复制, 粘贴, 删除, 移到文件夹
    System,
    Top,
    MutexSelf,
    Development,
};

// 定义双击事件形式
enum class DbClickEventType {
    Normal, // 一般
    Folder, // 文件夹
    MutilActions, // 多项式操作
    MutilSwitchActions, // 多项式操作切换
    RandomAction, // 随机操作
    BackPage, // 返回上一页
    NextPage, // 下一页
};

#endif // GLOBALDEFINE_H
