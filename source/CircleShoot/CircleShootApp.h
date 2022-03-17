#ifndef __CIRCLESHOOTAPP_H__
#define __CIRCLESHOOTAPP_H__

#include <SexyAppFramework/SexyAppBase.h>

namespace Sexy
{
    ///////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////
    class WidgetMover;
    class Board;
    class WorkerThread;
    class LevelParser;
    class LoadingScreen;
    class MainMenu;
    class PracticeScreen;
    class ProfileMgr;
    class HighScoreMgr;
    class UserProfile;
    class Buffer;

    class CircleShootApp : public SexyAppBase
    {
    public:
        WidgetMover *mWidgetMover = NULL;
        Board *mBoard = NULL;
        MainMenu *mMainMenu = NULL;
        PracticeScreen *mPracticeScreen = NULL;
        Widget *mAdventureScreen = NULL;
        Widget *mHelpScreen = NULL;
        Widget *mMoreGamesScreen = NULL;
        LoadingScreen *mLoadingScreen = NULL;
        Widget *mUnk11;
        WorkerThread *mWorkerThread = NULL;
        LevelParser *mLevelParser = NULL;
        ProfileMgr *mProfileMgr = NULL;
        HighScoreMgr *mHighScoreMgr = NULL;
        UserProfile *mProfile = NULL;
        Buffer mUnk17;

        int mLastSong = 0;
        int mLastSongSwitchTime = 0;
        int mSongId = 0;
        bool mUnk24;
        int mUnk28 = 0;
        int mUnk29;
        bool mUnk30;
        int mUnk31;
        int mMaxExecutions = 0;
        int mMaxPlays = 0;
        int mMaxTime = 0;
        bool mUnk35;

        CircleShootApp();
        virtual ~CircleShootApp();

        virtual void Init();
        virtual void Shutdown();
        virtual void UpdateFrames();
        virtual void ButtonDepress(int theId);

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

        void FinishStatsDialog();
        void DoStatsDialog(bool a1, bool a2);

        void DoCreateUserDialog();

        void SwitchSong(int id);

        void PlaySong(int id, bool fade, double fadeSpeed);

        void DoOptionsDialog();
        void FinishOptionsDialog(bool a2);
        bool CheckYesNoButton(int theButton);

        void ShowMainMenu();
        void ShowPracticeScreeen(bool a2);
    };

};

#endif
