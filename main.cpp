#include "MyMath.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1A_16_タナハラ_コア_タイトル";

//==============================
// 関数定義
//==============================

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    //==============================
    // 変数初期化
    //==============================

    Matrix4x4 orthographicMatrix = MakeOrthographicMatrix(-160.0f, 160.0f, 200.0f, 300.0f, 0.0f, 1000.0f);

    Matrix4x4 perspectiveFovMatrix = MakePerspectiveFovMatrix(0.63f, 1.33f, 0.1f, 1000.0f);

    Matrix4x4 viewportMatrix = MakeViewportMatrix(100.0f, 200.0f, 600.0f, 300.0f, 0.0f, 1.0f);

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        Novice::ScreenPrintf(0, 0, "OrthographicMatrix");
        MatrixScreenPrintf(0, kRowHeight, orthographicMatrix);


        Novice::ScreenPrintf(0, kRowHeight * 8, "perspectiveFovMatrix");
        MatrixScreenPrintf(0, kRowHeight * 9, perspectiveFovMatrix);

        Novice::ScreenPrintf(0, kRowHeight * 15, "viewportMatrix");
        MatrixScreenPrintf(0, kRowHeight * 16, viewportMatrix);

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
