#include "drawerfactorysolution.h"

template <typename Tfactory, typename Tscene>
std::unique_ptr<BaseDrawer> DrawerFactorySolution<Tfactory, Tscene>::createDrawer(Tscene *scene)
{
    std::shared_ptr<AbstractDrawerFactory> factory(new Tfactory(scene));

    return factory->createDrawer();
}
