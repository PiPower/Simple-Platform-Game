#pragma once
#include "DirectX.h"
#include "GraphicalObject.h"
#include <vector>
#include "Window.h"
#include "Camera.h"

class BoardMenager
{
public:
	BoardMenager(Graphics* pGFX,float BlockScale);
	void AddBlocks(std::vector<GraphicalObject* >& Rects, Window* wnd, std::wstring path,Camera& cam);
	void SaveBoard(std::string path, std::vector<GraphicalObject* >& Rects);
	void Draw();
private:
	struct PositionTransformer
	{
		DirectX::XMMATRIX transforms;
		float proportion;
	};
	struct Line
	{
		float x;
		float y;
		float R;
		float G;
		float B;

		float padd[3];
	};
private:
	float BlockScale;
	float proportion;
	float OffsetX;
	float OffsetY;
	float ScaleX;
	float ScaleY;
	float RotationAngle;
	Graphics* const pGFX = nullptr;
	std::vector<Line> Lines;
	PositionTransformer PosTranform;
	std::vector<GraphicalObject* > Blocks;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer> pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer>  pCBuffTranform;
};

