/*#include "../../stdafx.h"
#include "SDK\SDK Headers\Entitys.h"
#include "SDK\SDK.h"
#include "Globals.h"
#include "dllmain.cpp"
#include "SDK\SDK Headers\CClient.h"
#include "tracer.h"
class cbullet_tracer
class cbullet_tracer
{
public:
void log(IGameEvent * event);
void render();
private:
class cbullet_tracer_info
{
public:
cbullet_tracer_info(Vector src, Vector dst, float time, Color color)
{
this->src = src;
this->dst = dst;
this->time = time;
this->color = color;
}

Vector src, dst;
float time;
Color color;
};

std::vector<cbullet_tracer_info> logs;
};

void cbullet_tracer::log(IGameEvent* event)
{
//if we receive bullet_impact event
if (strstr(event->GetName(), "bullet_impact"))
{
//get the user who fired the bullet
auto index = Interfaces::Engine()->GetPlayerForUserID(event->GetInt("userid"));

//return if the userid is not valid or we werent the entity who was fireing
if (index != Interfaces::Engine()->GetLocalPlayer())
return;

//get local player
auto local = static_cast<C_BasePlayer*>(Interfaces::EntityList()->GetClientEntity(index));
if (!local)
return;

//get the bullet impact's position
Vector position(event->GetFloat("x"), event->GetFloat("y"), event->GetFloat("z"));

Ray_t ray;
ray.Init(local->GetEyePosition(), position);

//skip local player
CTraceFilter filter;
filter.pSkip = local;

//trace a ray
trace_t tr;
Interfaces::Trace()->TraceRay(ray, MASK_SHOT, &filter, &tr);

//use different color when we hit a player
auto color = (tr.m_pEnt && reinterpret_cast<C_BasePlayer*>(tr.m_pEnt)->IsPlayer()) ? Color(140, 29, 29, 220) : Color(255, 255, 0, 220);

//push info to our vector
logs.push_back(cbullet_tracer_info(local->GetEyePosition(), position, Interfaces::Globals()->curtime, color));
}
*/