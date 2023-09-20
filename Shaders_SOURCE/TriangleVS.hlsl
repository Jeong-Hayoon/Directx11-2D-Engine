
struct VTX_IN
{
    float3 vPos : POSITION;
    float4 vColor : COLOR;
};

struct VTX_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR;
};

cbuffer TRANSFORM : register(b0)
{
    float3 cbPos;
    int padd1;
    float3 cbScale;
    int padd2;
};

VTX_OUT VS_Test(VTX_IN _in)
{
    VTX_OUT output = (VTX_OUT) 0.f;
    
    //_in.vPos - 삼각형의 정점 위치
    //cbPos.xyz - Transform에서 물체가 이동한 위치
    output.vPos = float4(_in.vPos + cbPos.xyz * cbScale.x, cbScale.x);

    //output.vPos.xyz *= cbScale;

    //output.vPos *= 5.5f;
    output.vColor = _in.vColor;
    
    return output;
}
