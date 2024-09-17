#define UIT_VENDORIZE_EMP
#define UIT_SUPPRESS_MACRO_INSEEP_WARNINGS

#include "emp/math/Random.hpp"
#include "emp/web/Animate.hpp"
#include "emp/web/Document.hpp"
#include "emp/web/web.hpp"
#include "World.h"
#include "Org.h"
#include "ConfigSetup.h"
#include "emp/config/ArgManager.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/UrlParams.hpp"


emp::web::Document doc("target");
emp::web::Document settings("settings");

MyConfigType config;

class AEAnimator : public emp::web::Animate {

    // arena width and height
    const int num_h_boxes = 50;
    const int num_w_boxes = 50;
    const double RECT_SIDE = 10;
    const double width{num_w_boxes * RECT_SIDE};
    const double height{num_h_boxes * RECT_SIDE};
    emp::Random random{config.SEED()};
    OrgWorld world{random};




    emp::web::Canvas canvas{width, height, "canvas"};

    public:

    AEAnimator() {
        // shove canvas into the div
        // along with a control button
        // apply configuration query params and config files to config
        auto specs = emp::ArgManager::make_builtin_specs(&config);
        emp::ArgManager am(emp::web::GetUrlParams(), specs);
        am.UseCallbacks();
        if (am.HasUnused()) std::exit(EXIT_FAILURE);

        doc << canvas;
        doc << GetToggleButton("Toggle");
        doc << GetStepButton("Step");
        doc << " This program showcases organisms that attempt to sove 5 different tasks through calculations: (1) Finding a square, (2) Finding a cube, (3) Finding a square root, (4) Finding a cubic root, (5) Finding a cosine. As the user, you have the ability to use the configuration panel on the right hand side of this page to either change the population of the initial number of organims, or their randomness in initial placements. The organisms are rewarded different amounts of points for each different task solved; and, whenever they reach 20 points, they are allowed to reproduce and inject a new offspring into the world that has the 'genome' to solve the task as their parent did but with a slight mutation (hence simulating evolution).";
         // setup configuration panel
        random.ResetSeed(config.SEED());
        emp::prefab::ConfigPanel config_panel(config);
        config_panel.SetRange("START_NUM", "3", "100");
        config_panel.SetRange("SEED", "1", "9");
        config_panel.SetRange("MUTATION_RATE_NUM","0.02","1");
        settings << config_panel;
        

        world.SetPopStruct_Grid(num_w_boxes, num_h_boxes);
        world.Resize(num_h_boxes,num_w_boxes);
        
        for(int i = 0; i < config.START_NUM(); i++){
            Organism* new_org = new Organism(&world, 0.0);
            world.Inject(*new_org);
        }

        
    }

    void DoFrame() override {
        canvas.Clear();
        world.Update(config.MUTATION_RATE_NUM());

        int org_num = 0;
        for (int x = 0; x < num_w_boxes; x++){
             for (int y = 0; y < num_h_boxes; y++) {
                if (world.IsOccupied(org_num)) // make sure that there is an organism there
                {                                                
                    if (world.GetOrg(org_num).GetSpecies() == 1)
                    {                                                    
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "blue", "blue"); // Task 1 colorized
                    }
                    else if (world.GetOrg(org_num).GetSpecies() == 2) 
                    {                                                    
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "red", "red"); // Task 2 colorized
                    }
                    else if (world.GetOrg(org_num).GetSpecies() == 3) 
                    {                                                    
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "yellow", "yellow"); // Task 3 colorized
                    }
                    else if (world.GetOrg(org_num).GetSpecies() == 4) 
                    {                                                    
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "green", "green"); // Task 4 colorized
                    }
                    else
                    {
                        canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "purple", "purple"); // Task 5 colorized
                    }
                }
                else
                {
                    canvas.Rect(x * RECT_SIDE, y * RECT_SIDE, RECT_SIDE, RECT_SIDE, "black", "black"); // field
                }
                org_num++;
             }
        }

    }

};

AEAnimator animator;

int main() {animator.Step();}