#pragma once
#include <functional>
#include "Enum.h"

//座標用構造体
struct Vector2 {
	double x = 0.0;
	double y = 0.0;

	Vector2 operator + ( const Vector2& val ) const {
		return { x + val.x, y + val.y };
	}

	Vector2 operator - ( const Vector2& val ) const {
		return { x - val.x, y - val.y };
	}

	Vector2 operator * ( const double val ) const {
		return { x * val, y * val };
	}

	// 💡 追加：ベクトルとスカラーの割り算
	Vector2 operator / ( const double val ) const {
		return { x / val, y / val };
	}

	bool operator==( const Vector2& ) const = default;

	constexpr double LengthSq( ) const {
		return x * x + y * y;
	}

	double Length( ) const {
		return std::sqrt( x * x + y * y );
	}

	void Normalize( ) {
		double len = Length( );
		if ( len > 0.0 ) {
			x /= len;
			y /= len;
		}
	}

	Vector2 Normalized( ) const {
		double len = Length( );
		if ( len > 0.0 ) {
			return { x / len, y / len };
		}
		return { 0.0, 0.0 };
	}
};

//シーン切り替え用イベント
struct SceneChangeEvent {
	double change_time = 0.0;
	bool is_end = false;
	bool is_clear = false;
};

//素材取得数
struct MaterialCount {
	MaterialType type = MaterialType::None;
	int count = 0;
};

//タスク予約用構造体
struct DelayTask {
	double time_left = 0.0;
	std::function<void( )> action;
};