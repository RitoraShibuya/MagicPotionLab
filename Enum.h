#pragma once

//シーンの種類
enum class SceneType {
	None = 0,
	Title,
	Main,
	Result,
};

//素材の種類
enum class MaterialType {
	None = 0,
	Fire,
	Water,
	Grass,
	Dark,
};

//タイルの種類
enum class TileType {
	None = 0,
	Wall,
	Firld,
	Item,
};

enum class UIType {
	None = 0,
	Target,
	Timer,
	Floor,
	Score,
};

//プレイヤーの方向
enum class PlayerDirection {
	None = 0,
	Up,
	Down,
	Right,
	Left,
};

//カメラの状態
enum class CameraState {
	None = 0,
	Movable,
	Lock,
	LockX,
	LockY,
};

//フェード指定
enum class FadeState {
	None = 0,
	FadeIn,
	FadeOut,
};

//音楽タイプ
enum class SoundType {
	BGM = 0,
	SE,
};