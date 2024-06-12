#ifndef __CIRCLESHOOTAPP_H__
#define __CIRCLESHOOTAPP_H__

#include <SexyAppFramework/SexyAppBase.h>

namespace Sexy
{
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    class WidgetMover;
	class Widget;
    class Board;
    class WorkerThread;
    class LevelParser;
    class LoadingScreen;
    class MainMenu;
    class AdventureScreen;
    class PracticeScreen;
    class ProfileMgr;
    class HighScoreMgr;
    class UserProfile;
    class Buffer;

    class CircleShootApp : public SexyAppBase
    {
    public:
        WidgetMover *mWidgetMover;
        Board *mBoard;
        MainMenu *mMainMenu;
        PracticeScreen *mPracticeScreen;
        AdventureScreen *mAdventureScreen;
        Widget *mHelpScreen;
        Widget *mMoreGamesScreen;
        LoadingScreen *mLoadingScreen;
        Widget *mUnk11;
        WorkerThread *mWorkerThread;
        LevelParser *mLevelParser;
        ProfileMgr *mProfileMgr;
        HighScoreMgr *mHighScoreMgr;
        UserProfile *mProfile;
        Buffer mSaveGameBuffer;
        bool mDidNextTempleDialog;
        int mSongId;
        int mLastSong;
        int mLastSongSwitchTime;
        int mUnk28;
        int mUnk29;
        bool mUnk30;
        int mUnk31;
        int mMaxExecutions;
        int mMaxPlays;
        int mMaxTime;
        bool mIsPractice;
        int mUnk36;

        CircleShootApp();
        virtual ~CircleShootApp();

        virtual void Init();
        virtual void Shutdown();
        virtual void UpdateFrames();
        virtual void ButtonDepress(int theId);

        virtual Dialog* NewDialog(int theDialogId, bool isModal, const SexyString& theDialogHeader, const SexyString& theDialogLines, const SexyString& theDialogFooter, int theButtonMode);

        Board *GetBoard() { return mBoard; }

        void MakeBoard();
        void CleanupWidgets();
        void ShowLoadingScreen();
        void ShowHelpScreen();
        void StartAdventureGame(int theStage);
        void StartPracticeGame(const std::string &theLevelName, int theStartLevel, bool endless);

        bool CheckSaveGame(bool showConfirm);
        void StartSavedGame(bool showConfirm);

        void SaveProfile();
        void LoadingThreadProc();
        void LoadingThreadCompleted();

        void SwitchSong(int id);
        void PlaySong(int id, bool fade, double fadeSpeed);

        void DoConfirmQuitDialog();
        void DoCreateUserDialog();
        void DoNextTempleDialog();
        void DoOptionsDialog();
        void DoStatsDialog(bool a1, bool a2);

        void FinishConfirmQuitDialog(bool quit);
        void FinishCreateUserDialog(bool a2);
        void FinishRenameUserDialog(bool a2);
        void FinishNeedRegisterDialog(bool a2);
        void FinishRegisterDialog(bool a2);
        void FinishNextTempleDialog(bool save);
        void FinishConfirmContinueDialog(bool a2);
        void FinishGetReadyDialog();
        void FinishOptionsDialog(bool a2);
        void FinishConfirmMainMenuDialog(bool a2);
        void FinishStatsDialog(bool a2);

        bool CheckYesNoButton(int theButton);

        void ShowMainMenu();
        void ShowAdventureScreen(bool fromMenu, bool revealTemple);
        void ShowPracticeScreeen(bool fromMenu);
        void ShowMoreGamesScreen();
    };

};

#endif
