local L_1_ = "t"

local L_2_ = game.Players.LocalPlayer:GetMouse()

L_2_.KeyDown:Connect(

    function(L_22_arg0)

	if L_22_arg0 == L_1_ then

		if DaHoodSettings.SilentAim == true then

			DaHoodSettings.SilentAim = false

		else

			DaHoodSettings.SilentAim = true

		end

	end

end

)

game:GetService("RunService").RenderStepped:Connect(

    function()

	for L_23_forvar0, L_24_forvar1 in pairs(game.CoreGui:GetChildren()) do

		if L_24_forvar1.Name == "PostmansAutoRob" then

			L_24_forvar1:Destroy()

		end

	end

	for L_25_forvar0, L_26_forvar1 in pairs(game.CoreGui:GetChildren()) do

		if L_26_forvar1.Name == "WarningGUI" then

			L_26_forvar1:Destroy()

		end

	end

end

)

game.StarterGui:SetCore(

    "SendNotification",

    {

	Title = "Hello World!",

	Text = "aim.cc",

}

)

local L_3_ = loadstring(game:HttpGet("https://raw.githubusercontent.com/xHeptc/Kavo-UI-Library/main/source.lua")), true()

local L_4_ = L_3_.CreateLib("aim.cc", "Ocean")

local L_5_ = L_4_:NewTab("Aimlock")

local L_6_ = L_5_:NewSection("discord.gg/ZaMYzpf6Ah")

L_6_:NewButton(

    "Aimlock",

    "Aim Lock Lol",

    function()

	getgenv().AimPart = "HumanoidRootPart"

	getgenv().AimlockKey = "q"

	getgenv().AimRadius = 30

	getgenv().ThirdPerson = true

	getgenv().FirstPerson = true

	getgenv().TeamCheck = false

	getgenv().PredictMovement = true

	getgenv().PredictionVelocity = 9

	local L_27_, L_28_, L_29_, L_30_ =

            game:GetService "Players",

            game:GetService "UserInputService",

            game:GetService "RunService",

            game:GetService "StarterGui"

	local L_31_, L_32_, L_33_, L_34_, L_35_, L_36_, L_37_ =

            L_27_.LocalPlayer,

            L_27_.LocalPlayer:GetMouse(),

            workspace.CurrentCamera,

            CFrame.new,

            Ray.new,

            Vector3.new,

            Vector2.new

	local L_38_, L_39_, L_40_ = true, false, false

	local L_41_

	getgenv().CiazwareUniversalAimbotLoaded = true

	getgenv().WorldToViewportPoint = function(L_42_arg0)

		return L_33_:WorldToViewportPoint(L_42_arg0)

	end

	getgenv().WorldToScreenPoint = function(L_43_arg0)

		return L_33_.WorldToScreenPoint(L_33_, L_43_arg0)

	end

	getgenv().GetObscuringObjects = function(L_44_arg0)

		if L_44_arg0 and L_44_arg0:FindFirstChild(getgenv().AimPart) and L_31_ and L_31_.Character:FindFirstChild("Head") then

			local L_45_ = workspace:FindPartOnRay(L_35_(L_44_arg0[getgenv().AimPart].Position, L_31_.Character.Head.Position))

			if L_45_ then

				return L_45_:IsDescendantOf(L_44_arg0)

			end

		end

	end

	getgenv().GetNearestTarget = function()

		local L_46_ = {}

		local L_47_ = {}

		local L_48_ = {}

		for L_50_forvar0, L_51_forvar1 in pairs(L_27_:GetPlayers()) do

			if L_51_forvar1 ~= L_31_ then

				table.insert(L_46_, L_51_forvar1)

			end

		end

		for L_52_forvar0, L_53_forvar1 in pairs(L_46_) do

			if L_53_forvar1.Character ~= nil then

				local L_54_ = L_53_forvar1.Character:FindFirstChild("Head")

				if getgenv().TeamCheck == true and L_53_forvar1.Team ~= L_31_.Team then

					local L_55_ =

                            (L_53_forvar1.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude

					local L_56_ =

                            Ray.new(

                            game.Workspace.CurrentCamera.CFrame.p,

                            (L_32_.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * L_55_

                        )

					local L_57_, L_58_ = game.Workspace:FindPartOnRay(L_56_, game.Workspace)

					local L_59_ = math.floor((L_58_ - L_54_.Position).magnitude)

					L_47_[L_53_forvar1.Name .. L_52_forvar0] = {}

					L_47_[L_53_forvar1.Name .. L_52_forvar0].dist = L_55_

					L_47_[L_53_forvar1.Name .. L_52_forvar0].plr = L_53_forvar1

					L_47_[L_53_forvar1.Name .. L_52_forvar0].diff = L_59_

					table.insert(L_48_, L_59_)

				elseif getgenv().TeamCheck == false and L_53_forvar1.Team == L_31_.Team then

					local L_60_ =

                            (L_53_forvar1.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude

					local L_61_ =

                            Ray.new(

                            game.Workspace.CurrentCamera.CFrame.p,

                            (L_32_.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * L_60_

                        )

					local L_62_, L_63_ = game.Workspace:FindPartOnRay(L_61_, game.Workspace)

					local L_64_ = math.floor((L_63_ - L_54_.Position).magnitude)

					L_47_[L_53_forvar1.Name .. L_52_forvar0] = {}

					L_47_[L_53_forvar1.Name .. L_52_forvar0].dist = L_60_

					L_47_[L_53_forvar1.Name .. L_52_forvar0].plr = L_53_forvar1

					L_47_[L_53_forvar1.Name .. L_52_forvar0].diff = L_64_

					table.insert(L_48_, L_64_)

				end

			end

		end

		if unpack(L_48_) == nil then

			return nil

		end

		local L_49_ = math.floor(math.min(unpack(L_48_)))

		if L_49_ > getgenv().AimRadius then

			return nil

		end

		for L_65_forvar0, L_66_forvar1 in pairs(L_47_) do

			if L_66_forvar1.diff == L_49_ then

				return L_66_forvar1.plr

			end

		end

		return nil

	end

	L_32_.KeyDown:Connect(

            function(L_67_arg0)

		if L_67_arg0 == AimlockKey and L_41_ == nil then

			pcall(

                        function()

				if L_39_ ~= true then

					L_39_ = true

				end

				local L_68_

				L_68_ = GetNearestTarget()

				if L_68_ ~= nil then

					L_41_ = L_68_

				end

			end

                    )

		elseif L_67_arg0 == AimlockKey and L_41_ ~= nil then

			if L_41_ ~= nil then

				L_41_ = nil

			end

			if L_39_ ~= false then

				L_39_ = false

			end

		end

	end

        )

	L_29_.RenderStepped:Connect(

            function()

		if getgenv().ThirdPerson == true and getgenv().FirstPerson == true then

			if

                        (L_33_.Focus.p - L_33_.CoordinateFrame.p).Magnitude > 1 or

                            (L_33_.Focus.p - L_33_.CoordinateFrame.p).Magnitude <= 1

                     then

				L_40_ = true

			else

				L_40_ = false

			end

		elseif getgenv().ThirdPerson == true and getgenv().FirstPerson == false then

			if (L_33_.Focus.p - L_33_.CoordinateFrame.p).Magnitude > 1 then

				L_40_ = true

			else

				L_40_ = false

			end

		elseif getgenv().ThirdPerson == false and getgenv().FirstPerson == true then

			if (L_33_.Focus.p - L_33_.CoordinateFrame.p).Magnitude <= 1 then

				L_40_ = true

			else

				L_40_ = false

			end

		end

		if L_38_ == true and L_39_ == true then

			if L_41_ and L_41_.Character and L_41_.Character:FindFirstChild(getgenv().AimPart) then

				if getgenv().FirstPerson == true then

					if L_40_ == true then

						if getgenv().PredictMovement == true then

							L_33_.CFrame =

                                        L_34_(

                                        L_33_.CFrame.p,

                                        L_41_.Character[getgenv().AimPart].Position +

                                            L_41_.Character[getgenv().AimPart].Velocity / PredictionVelocity

                                    )

						elseif getgenv().PredictMovement == false then

							L_33_.CFrame = L_34_(L_33_.CFrame.p, L_41_.Character[getgenv().AimPart].Position)

						end

					end

				elseif getgenv().ThirdPerson == true then

					if L_40_ == true then

						if getgenv().PredictMovement == true then

							L_33_.CFrame =

                                        L_34_(

                                        L_33_.CFrame.p,

                                        L_41_.Character[getgenv().AimPart].Position +

                                            L_41_.Character[getgenv().AimPart].Velocity / PredictionVelocity

                                    )

						elseif getgenv().PredictMovement == false then

							L_33_.CFrame = L_34_(L_33_.CFrame.p, L_41_.Character[getgenv().AimPart].Position)

						end

					end

				end

			end

		end

	end

        )

end

)

L_6_:NewTextBox(

    "Aimlock Key",

    "Aimlock Key should be lowercase.",

    function(L_69_arg0)

	getgenv().AimlockKey = L_69_arg0

end

)

L_6_:NewTextBox(

    "Aimlock Prediction",

    "Customize your aimlock prediction",

    function(L_70_arg0)

	PredictionVelocity = L_70_arg0

end

)

L_6_:NewDropdown(

    "AimPart",

    "",

    {

	"Head",

	"UpperTorso",

	"HumanoidRootPart",

	"LowerTorso"

},

    function(L_71_arg0)

	getgenv().AimPart = L_71_arg0

end

)

local L_7_ = L_4_:NewTab("Silent Aim")

local L_8_ = L_7_:NewSection("discord.gg/ZaMYzpf6Ah")

L_8_:NewButton(

    "Silent Aim",

    "Silent Aim Toggle Key is T.",

    function()

	loadstring(game:HttpGet("https://raw.githubusercontent.com/sync14/aim.cc/main/silent1", true))()

end

)

L_8_:NewTextBox(

    "Silent Aim Prediction",

    "0.157 for low ping 0.178 high ping",

    function(L_72_arg0)

	DaHoodSettings.Prediction = L_72_arg0

end

)

L_8_:NewDropdown(

    "Silent Aim Part",

    "Shooting to Humanoid Part",

    {

	"Head",

	"UpperTorso",

	"HumanoidRootPart",

	"LowerTorso"

},

    function(L_73_arg0)

	Aiming.TargetPart = L_73_arg0

end

)

L_8_:NewTextBox(

    "Silent Aim Fov",

    "Legit = 10-40, Rage = 100-500",

    function(L_74_arg0)

	Aiming.FOV = L_74_arg0

end

)

L_8_:NewToggle(

    "Silent Aim Show Fov",

    "Shows Silent Aim Fov",

    function(L_75_arg0)

	Aiming.ShowFOV = L_75_arg0

end

)

local L_11_ = L_4_:NewTab("Antilock")

local L_12_ = L_11_:NewSection("discord.gg/ZaMYzpf6Ah")

L_12_:NewButton(

    "Anti-Lock",

    "Key is Z.",

    function()

	repeat

		wait()

	until game:IsLoaded()

	getgenv().Fix = true

	getgenv().TeclasWS = {

		["tecla1"] = "nil",

		["tecla2"] = "nil",

		["tecla3"] = "H"

	}

	local L_121_ = game:GetService("Players")

	local L_122_ = game:GetService("StarterGui") or "son una mierda"

	local L_123_ = L_121_.LocalPlayer

	local L_124_ = L_123_:GetMouse()

	local L_125_ = getrenv()._G

	local L_126_ = getrawmetatable(game)

	local L_127_ = L_126_.__newindex

	local L_128_ = L_126_.__index

	local L_129_ = 22

	local L_130_ = true

	function anunciar_atentado_terrorista(L_138_arg0)

		L_122_:SetCore("SendNotification", {

			Title = "anti lock fix",

			Text = L_138_arg0

		})

	end

	getgenv().TECHWAREWALKSPEED_LOADED = true

	wait(1.5)

	anunciar_atentado_terrorista("Press  " .. TeclasWS.tecla3 .. " to turn on/off anti lock fix")

	L_124_.KeyDown:Connect(

            function(L_139_arg0)

		if L_139_arg0:lower() == TeclasWS.tecla1:lower() then

			L_129_ = L_129_ + 1

			anunciar_atentado_terrorista("æ­æ¾å¨éåº¦å·²æé« (speed = " .. tostring(L_129_) .. ")")

		elseif L_139_arg0:lower() == TeclasWS.tecla2:lower() then

			L_129_ = L_129_ - 1

			anunciar_atentado_terrorista("ç©å®¶çéåº¦å·²éä½ (speed = " .. tostring(L_129_) .. ")")

		elseif L_139_arg0:lower() == TeclasWS.tecla3:lower() then

			if L_130_ then

				L_130_ = false

				anunciar_atentado_terrorista("anti lock fix off")

			else

				L_130_ = true

				anunciar_atentado_terrorista("anti lock fix on")

			end

		end

	end

        )

	setreadonly(L_126_, false)

	L_126_.__index =

            newcclosure(

            function(L_140_arg0, L_141_arg1)

		local L_142_ = checkcaller()

		if L_141_arg1 == "WalkSpeed" and not L_142_ then

			return L_125_.CurrentWS

		end

		return L_128_(L_140_arg0, L_141_arg1)

	end

        )

	L_126_.__newindex =

            newcclosure(

            function(L_143_arg0, L_144_arg1, L_145_arg2)

		local L_146_ = checkcaller()

		if L_130_ then

			if L_144_arg1 == "WalkSpeed" and L_145_arg2 ~= 0 and not L_146_ then

				return L_127_(L_143_arg0, L_144_arg1, L_129_)

			end

		end

		return L_127_(L_143_arg0, L_144_arg1, L_145_arg2)

	end

        )

	setreadonly(L_126_, true)

	repeat

		wait()

	until game:IsLoaded()

	local L_131_ = game:service("Players")

	local L_132_ = L_131_.LocalPlayer

	repeat

		wait()

	until L_132_.Character

	local L_133_ = game:service("UserInputService")

	local L_134_ = game:service("RunService")

	local L_135_ = -0.27

	local L_136_ = false

	local L_137_

	L_133_.InputBegan:connect(

            function(L_147_arg0)

		if L_147_arg0.KeyCode == Enum.KeyCode.LeftBracket then

			L_135_ = L_135_ + 0.01

			print(L_135_)

			wait(0.2)

			while L_133_:IsKeyDown(Enum.KeyCode.LeftBracket) do

				wait()

				L_135_ = L_135_ + 0.01

				print(L_135_)

			end

		end

		if L_147_arg0.KeyCode == Enum.KeyCode.RightBracket then

			L_135_ = L_135_ - 0.01

			print(L_135_)

			wait(0.2)

			while L_133_:IsKeyDown(Enum.KeyCode.RightBracket) do

				wait()

				L_135_ = L_135_ - 0.01

				print(L_135_)

			end

		end

		if L_147_arg0.KeyCode == Enum.KeyCode.Z then

			L_136_ = not L_136_

			if L_136_ == true then

				repeat

					game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame =

                                game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame +

                                game.Players.LocalPlayer.Character.Humanoid.MoveDirection * L_135_

					game:GetService("RunService").Stepped:wait()

				until L_136_ == false

			end

		end

	end

        )

end

)

local L_13_ = L_4_:NewTab("Player")

local L_14_ = L_13_:NewSection("discord.gg/ZaMYzpf6Ah")

L_14_:NewDropdown(

    "Fov",

    "Changes Field of View",

    {"40", "50", "60", "70", "80", "90", "100", "110", "120"}, function(currentOption)

    workspace.CurrentCamera.FieldOfView = (currentOption)

end

)

L_14_:NewButton(

    "Fake Macro",

    "Macro",

    function()

loadstring(game:HttpGet("https://pastebin.com/raw/KuiBEQ8s", true))()

end

)

L_14_:NewButton(

    "Anti Stomp",

    "Anyone Dont Stomp You",

    function()

loadstring(game:HttpGet("https://raw.githubusercontent.com/BlueaqeR/scripts-lol/main/Da%20Hood%20Anti%20Stomp%20(Optimized)"))(wc)

end

)

L_14_:NewButton(

    "Fly Script",

    "Best Fly Script",

    function()

loadstring(game:HttpGet("https://pastebin.com/raw/RBuwnuuv", true))()

end

)

L_14_:NewButton(

    "FullBright",

    "You can See in Dark Rooms",

    function()

loadstring(game:HttpGet("https://pastebin.com/raw/7S3aQsQF", true))()

end)

local L_17_ = L_4_:NewTab("ESP")

local L_18_ = loadstring(game:HttpGet("https://raw.githubusercontent.com/sync14/aim.cc/main/esp.cc"))()

local L_19_ = L_17_:NewSection("discord.gg/ZaMYzpf6Ah")

L_19_:NewToggle(

    "ESP",

    "ESP",

    function(L_201_arg0)

	L_18_:Toggle(L_201_arg0)

end

)

L_19_:NewToggle(

    "Tracers",

    "ESP Tracers",

    function(L_202_arg0)

	L_18_.Tracers = L_202_arg0

end

)

L_19_:NewToggle(

    "Names",

    "ESP Names",

    function(L_203_arg0)

	L_18_.Names = L_203_arg0

end

)

L_19_:NewToggle(

    "Boxes",

    "ESP Boxes",

    function(L_204_arg0)

	L_18_.Boxes = L_204_arg0

end

)

local L_20_ = L_4_:NewTab("Settings")

local L_21_ = L_20_:NewSection("discord.gg/ZaMYzpf6Ah")

L_21_:NewKeybind(

    "Keybind Gui Toggle",

    "Toggle GUI",

    Enum.KeyCode.C,

    function()

	L_3_:ToggleUI()

end

)

L_21_:NewButton(

"Coordinates Grabber",

"Stealing Coordinates",

function()

loadstring(game:HttpGet("https://pastebin.com/raw/GdmzzrDz", true))()

end)

local L_22_ = L_4_:NewTab("Teleports")

local L_23_ = L_22_:NewSection("discord.gg/ZaMYzpf6Ah")

L_23_:NewButton(

     "TP to DB",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-1042.8541259765625, 21.74802017211914, -259.9525451660156)

end

)

L_23_:NewButton(

     "TP to High-Med Armor",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-934.7604370117188, -28.501983642578125, 564.9243774414062)

end

)

L_23_:NewButton(

     "TP to Aug",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-270.792724609375, 52.26165008544922, -226.96932983398438)

end

)

L_23_:NewButton(

     "TP to DownHill Med Armor",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-607.1241455078125, 10.347716331481934, -795.8753662109375)

end

)

L_23_:NewButton(

     "TP to DownHill Gunz",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-581.6777954101562, 8.312806129455566, -736.2597045898438)

end

)

L_23_:NewButton(

     "TP to Box",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-259.8877258300781, 22.5684871673584, -1121.8729248046875)

end

)

L_23_:NewButton(

     "TP to Admin Base",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-796.4783935546875, -39.651187896728516, -885.6860961914062)

end

)

L_23_:NewButton(

     "TP to UpHill Gunz",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(482.1127624511719, 48.06852722167969, -622.0449829101562)

end

)

L_23_:NewButton(

     "TP to UpHill Armor",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(526.9901123046875, 50.3111572265625, -630.0726318359375)

end

)

L_23_:NewButton(

     "TP to Revolver",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-643.385498046875, 21.74802017211914, -121.16966247558594)

end

)

L_23_:NewButton(

     "TP to Flamethrower",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-153.76504516601562, 53.80862808227539, -99.72679901123047)

end

)

L_23_:NewButton(

     "TP to Bank",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-454.3135681152344, 39.02350616455078, -286.256591796875)

end

)

L_23_:NewButton(

     "TP to RPG",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(111.62887573242188, -26.752010345458984, -275.60284423828125)

end

)

L_23_:NewButton(

     "TP to Safe Place #1 (Need FullBright)",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-4.78402853012085, -103.45206451416016, 137.65066528320312)

end

)

L_23_:NewButton(

     "TP to Safe Place #2",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new()

end

)

L_23_:NewButton(

     "TP to DownHill Foods",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-325.664794921875, 23.680667877197266, -297.2865295410156)

end

)

L_23_:NewButton(

     "TP to UpHill Foods",

     "Teleport",

     function()

game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(298.3734436035156, 49.280677795410156, -620.7047119140625)

end

)
